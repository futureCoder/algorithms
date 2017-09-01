typedef std::function<void()> CallBackT;

template<typename T>
class SimpleCallBackWrapper
{
    private:
        T fun_;
        CallBackT cb_;

        void onStart() { cout << "start!" << endl; }
    public:
        SimpleCallBackWrapper(T&& fun, const CallBackT& cb):
            fun_(fun), cb_(cb) { onStart(); }
        SimpleCallBackWrapper(const T& fun, const CallBackT& cb):
            fun_(fun), cb_(cb) { onStart(); }
        template<typename... Args>
            void operator()(Args&&... args)
            {
                fun_(std::forward<Args>(args)...);
                cb_();
            }
};

template<typename T> 
SimpleCallBackWrapper<typename std::remove_reference<T>::type>
makeSimpleCallbackWrapper(T&& fun, const CallBackT& cb)
{
    return SimpleCallBackWrapper<typename std::remove_reference<T>::type>
        (std::forward<T>(fun), cb);
}


void onEnd()
{
    cout << "End!" << endl;
}

void worker_thread(int num)
{
    for (int i=0; i<5; ++i)
    {

        cout << "thread"<<num<<" is working ("<<(i+1)<<"/5)"<<endl;
    }
}

int main()
{
    std::thread t(makeSimpleCallbackWrapper(&worker_thread, &onEnd), 1);
    t.join();
    //start!
    //thread1 is working (1/5)
    //thread1 is working (2/5)
    //thread1 is working (3/5)
    //thread1 is working (4/5)
    //thread1 is working (5/5)
    //End!
}