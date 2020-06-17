#ifndef _FLYWEIGHT_H
#define _FLYWEIGHT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class FlyWeight{
public:
    FlyWeight(std::string gender,std::string addr);
    virtual void Operator() = 0;
protected:
    std::string m_gender;
    std::string m_addr;
};

class ConcreteFlyWeight : public FlyWeight{
public:
    ConcreteFlyWeight(std::string gender,std::string addr);
     virtual void Operator();
};

class UnsharedConcreteFlyWeight : public FlyWeight {
public:
    UnsharedConcreteFlyWeight(std::string gender,std::string addr);
    virtual void Operator();
};

struct stusInfo{
    int m_age;
    FlyWeight* m_pFlyweight;
};

class FlyWeightFactory {
public:
    void inputStudentInfo(std::string key,int age,std::string gender,std::string addr);
    FlyWeight* getInstance(std::string key,std::string gender,std::string addr);
    void print();
public:
    std::map<std::string,FlyWeight*> sharedWeight;
    // 保存本地学生的信息。若学生身份为本地且相应的内部状态未创建，
    // 则新建内部状态并保存到该容器中。
    std::vector<stusInfo*> m_pStudentInfos;
};

#endif