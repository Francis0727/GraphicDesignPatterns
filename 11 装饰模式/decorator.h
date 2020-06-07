#ifndef _DECORATOR_H
#define _DECORATOR_H

#include <iostream>

class Component {
public:
    virtual void Operation() = 0;
};

class ConcreteComponent : public Component {
public:
    virtual void Operation();
} ;

class Decorator : public Component {
public:
    Decorator(Component* m_pComponent);
    virtual void Operation() = 0;
protected:
    Component* m_pComponent;
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* pComponent);
    void AddBehavor();
    virtual void Operation();
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* pComponent);
    void AddBehavor();
    virtual void Operation();
};

#endif