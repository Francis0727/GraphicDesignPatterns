#ifndef _PROXY_H
#define _PROXY_H

#include <iostream>

class Subject {
public:
    virtual void request() = 0;
};

class ConcreteSubject : public Subject {
public:
    virtual void request();
};

class Proxy : public Subject {
public:
    Proxy();
    ~Proxy();
    void doSomething(void); 
    virtual void request();
protected:
    Subject* m_pSubject;
};

#endif