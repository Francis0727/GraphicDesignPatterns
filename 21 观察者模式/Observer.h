#ifndef _OBSERVER_H
#define _OBSERVER_H

#include <string>
#include <list>
#include <iostream>

class Subject;
class Observer{
public:
    virtual void update(Subject* pSubject) = 0;
};

class ConcreteObserverA : public Observer {
public:
    virtual void update(Subject* pSubject);
private:
    std::string m_state;
};

class ConcreteObserverB : public Observer{
public:
    virtual void update(Subject* pSubject);
private:
    std::string m_state;
};

class Subject {
public:
    virtual void attach(Observer* obj);
    virtual std::string getState();
    virtual void setState(std::string state);
    void notify();
private:
    std::string m_state;
    std::list<Observer*> m_observer;
};

class ConcreteSubjectA : public Subject{

};

class ConcreteSubjectB : public Subject{

};

#endif