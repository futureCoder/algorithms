#ifndef _singleton_h_
#define _singleton_h_

enum MemType {
	MT_UNKNOWN = 0,
	MT_HEAP_NEW,
	MT_HEAP_MALLOC,
	MT_STACK,
};

template<class T>
class Singleton {
public:
	Singleton(){}
	virtual ~Singleton(){}

	static inline T& Instance() {return *InstancePtr();}
	static inline T* InstancePtr() {
		if(nullptr == m_ptr) {
			m_ptr = (T*)
#ifdef _Client
			std::operator new
#else
			malloc
#endif
			(sizeof(T));
			if(m_ptr) {
				m_type = MT_HEAP_MALLOC;
				new(m_ptr)T();
			}
		}
	}

private:
	static T* m_ptr;
	static MemType m_type;

}