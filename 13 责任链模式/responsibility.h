#ifndef _RESPONSIBILITY_H
#define _RESPONSIBILITY_H

#include <string>
#include <iostream>

class Support {
public:
    Support(std::string name);
    // 建立责任链，即以链表的形式将子类串联起来。
    Support* setNext(Support* nextSupport);
    void approve(double amountMoney);
    virtual bool resolve(double money);
protected:
    std::string m_name;
    Support* m_nextSupport;
};

// 有权审批金额小于100的申请
class NoSupport : public Support {
public:
    NoSupport(std::string name);
    virtual bool resolve(double money);
};

// 有权审批金额小于200的申请
class LimitSupport : public Support {
public:
    LimitSupport(std::string name);
    virtual bool resolve(double money);
};

class OddSupport : public Support {
public:
    OddSupport(std::string name);
    virtual bool resolve(double money);
};

class SpecialSupport : public Support {
public:
    SpecialSupport(std::string name);
    virtual bool resolve(double money);
};
#endif