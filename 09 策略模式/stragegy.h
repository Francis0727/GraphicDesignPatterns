#ifndef _STRAGETY_H
#define _STRAGETY_H

#include <iostream>

class Strategy{
public:
    virtual void Tax() = 0;
};

class ConcreteStrageA : public Strategy {
public:
    virtual void Tax();
};

class ConcreteStrageB : public Strategy {
public:
    virtual void Tax();
};

class Context{
public:
    Context(Strategy* pStrategy);
    void doAction();
    void setStragety(Strategy* pStragety);
private:
    Strategy* m_pStrategy;
};

#endif