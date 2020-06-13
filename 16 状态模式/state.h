#ifndef _STATE_H
#define _STATE_H

#include <iostream>

class Context;
class State {
public:
    virtual void handle(Context* pContext) = 0;
};

class ConcreteStateA : public State {
public:
    static State* getInstance();
    virtual void handle(Context* pContext);
private:
    static State* m_pState;
};

class ConcreteStateB : public State {
public:
    static State* getInstance();
    virtual void handle(Context* pContext);
private:
    static State* m_pState;
};

class Context {
public:
    void changeState(State* pState);
    void request();
    Context();
private:
    State* m_pStatus;
};

#endif