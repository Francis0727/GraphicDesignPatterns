#ifndef _MEDIATOR_H
#define _MEDIATOR_H

#include <string>
#include <iostream>
#include <map>

class Colleage;
class Mediator{
public:
    virtual void sendMessage(std::string name,std::string msg) = 0;
};

class ConcreteMediator : public Mediator{
public:
    void setColleage(std::string name,Colleage* pColleage);
    void sendMessage(std::string name,std::string msg);
private:
    std::map<std::string,Colleage*> m_pColleageMap;
};

class Colleage{
public:
    Colleage(Mediator* pMediator);
    virtual void getMessage(std::string msg) = 0;
    virtual void sendMessage(std::string name,std::string msg) = 0;  
protected:
    Mediator* m_pMediator;
};

class ConcreteColleage : public Colleage {
public:
    ConcreteColleage(Mediator* pMediator);
    virtual void getMessage(std::string msg);
    virtual void sendMessage(std::string name,std::string msg);
};

#endif