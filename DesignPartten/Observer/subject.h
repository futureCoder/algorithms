#ifndef SUBJECT_H  
#define SUBJECT_H  
  
#include <string>  
#include <list>  
  
class Observer;  
  
//Subject，抽象通知者或者主题  
class Subject  
{  
protected:  
    std::string SubjectState;  
public:  
    virtual void Attach(Observer* observer)=0;  
    virtual void Detach(Observer* observer)=0;  
    virtual void Notify()=0;  
    std::string GetSubjectState();  
    void SetSubjectState(std::string state);  
};  
  
//ConcreteSubject，具体通知者或者具体主题。  
class Boss:public Subject  
{  
private:  
    std::list<Observer*> observers;  
    std::string action;  
public:  
    void Attach(Observer* observer);  
    void Detach(Observer* observer);  
    void Notify();  
};  
  
#endif  
