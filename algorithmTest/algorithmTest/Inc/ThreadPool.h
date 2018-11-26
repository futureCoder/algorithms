#ifndef _THREADPOOL__H_
#define _THREADPOOL__H_
#include <vector>
#include <thread>
#include <utility>
#include <queue>
#include <future>
#include <condition_variable>
using namespace std;
class ThreadPool {
public:

	// ���̳߳��д��� threads �������߳�
	ThreadPool(size_t threads);

	// ���̳߳��������߳�
	template<typename F, typename... Args>
	auto enqueue(F&& f, Args&&... args)
		->std::future<typename std::result_of<F(Args...)>::type>;

	~ThreadPool();
private:
	// ��Ҫ����׷���߳�����֤����ʹ�� join
	std::vector< std::thread > workers;
	// �������
	std::queue< std::function<void()> > tasks;

	// ͬ�����
	std::mutex queue_mutex;             // ������
	std::condition_variable condition;  // ������������

	// ֹͣ���
	bool stop;
};

// ���캯��ֻ��������һ�������Ĺ����߳�(worker)
inline ThreadPool::ThreadPool(size_t threads)
	: stop(false)
{
	// ���� threads �����Ĺ����߳�(worker)
	for (size_t i = 0; i<threads; ++i)
		workers.emplace_back(
			// �˴��� lambda ���ʽ���� this, ���̳߳�ʵ��
			[this]
	{
		// ѭ��������ٻ���
		for (;;)
		{
			// ���庯�����������, �洢����ķ�������Ϊ void ������Ϊ�յĺ���
			std::function<void()> task;

			// �ٽ���
			{
				// ����������
				std::unique_lock<std::mutex> lock(this->queue_mutex);

				// ������ǰ�߳�, ֱ�� condition_variable ������
				this->condition.wait(lock,
					[this] { return this->stop || !this->tasks.empty(); });

				// �����ǰ�̳߳��Ѿ������ҵȴ��������Ϊ��, ��Ӧ��ֱ�ӷ���
				if (this->stop && this->tasks.empty())
					return;

				// �������������еĶ���������Ϊ��Ҫִ�е��������
				task = std::move(this->tasks.front());
				this->tasks.pop();
			}

			// ִ�е�ǰ����
			task();
		}
	}
	);
}

// ���������̳߳��д������߳�
inline ThreadPool::~ThreadPool()
{
	// �ٽ���
	{
		// ����������
		std::unique_lock<std::mutex> lock(queue_mutex);

		// �����̳߳�״̬
		stop = true;
	}

	// ֪ͨ���еȴ��߳�
	condition.notify_all();

	// ʹ�����첽�߳�תΪͬ��ִ��, �˴�ѭ��Ϊ c++11 ���ṩ��ѭ���﷨ for(value:values)
	for (std::thread &worker : workers)
		worker.join();
}

// ���һ���µ��̵߳��̳߳���
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
-> std::future<typename std::result_of<F(Args...)>::type>
{
	// �Ƶ����񷵻�����
	using return_type = typename std::result_of<F(Args...)>::type;

	// ��õ�ǰ����
	auto task = std::make_shared< std::packaged_task<return_type()> >(
		std::bind(std::forward<F>(f), std::forward<Args>(args)...)
		);

	// ��� std::future �����Թ�ʵʩ�߳�ͬ��
	std::future<return_type> res = task->get_future();

	// �ٽ���
	{
		std::unique_lock<std::mutex> lock(queue_mutex);

		// ��ֹ���̳߳�ֹͣ������µ��߳�
		if (stop)
			throw std::runtime_error("enqueue on stopped ThreadPool");

		// ���߳���ӵ�ִ�����������
		tasks.emplace([task] { (*task)(); });
	}

	// ֪ͨһ�����ڵȴ����߳�
	condition.notify_one();
	return res;
}

#endif // !_THREADPOOL__H_
