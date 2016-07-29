#include <iostream>
using namespace std;
template<class T>
class SingletonLhan {
public:
	SingletonLhan() {}
	~SingletonLhan() {}
	static inline T& Instance() {return *InstancePtr();}
	static inline T* InstancePtr() {
		if(nullptr == m_ptr) {
			m_ptr = new T();
		}
		return m_ptr;
	}
private:
	static T* m_ptr;
};

template<class T>
class SingletonEhan {
public:
	SingletonEhan() {}
	~SingletonEhan() {}
	static inline T& Instance() {return *InstancePtr();}
	static inline T* InstancePtr() {
		return m_ptr;
	}
private:
	static T* m_ptr;
};
template<class T>
T* SingletonEhan<T>::m_ptr = new T();
template<class T>
T* SingletonLhan<T>::m_ptr = nullptr;

class LA : public SingletonLhan<LA> {
public:
	LA(){
		la = 2;
		cout << "la" << endl;
	}
	~LA(){
		cout << "~la" << endl;
	}
	int la;
};

class EA : public SingletonEhan<EA> {
public:
	EA(){}
	~EA(){}
};

int main() {
	LA *la = LA::InstancePtr();
	EA *ea = EA::InstancePtr();
	LA *la2 = (LA*)operator new(sizeof(LA));
	cout << la2 <<" - " << la2->la << endl;
	new(la2)LA();
	cout << la2 <<" - " << la2->la << endl;
	
	
}
