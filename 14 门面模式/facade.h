#ifndef _FACADE_H
#define _FACADE_H

#include <iostream>

class SubSystemA{
public:
    void Operator();
};

class SubSystemB{
public:
    void Operator();
};

class Facade {
public:
    Facade();
    ~Facade();
    void OperatorWrapper();
private:
    // 注: 类成员变量指向的对象在构造函数中生成
    SubSystemA* m_pSystemA;
    SubSystemB* m_pSystemB;
};

#endif