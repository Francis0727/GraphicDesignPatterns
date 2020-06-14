#include "mediator.h"

// 函数功能: 向同事通信录里添加新同事联系信息
// name： 新同事的名称
// pColleage: 新同事的具体联系方式
void ConcreteMediator::setColleage(std::string name,Colleage* pColleage) {
    if (!m_pColleageMap.count(name)){
        m_pColleageMap.insert(std::pair<std::string,Colleage*>(name,pColleage));
    }
}

// 函数功能: 向同事发送消息
// name: 同事的名称
// msg: 发生给同事的具体信息
void ConcreteMediator::sendMessage(std::string name,std::string msg) {
    std::map<std::string,Colleage*>::iterator ite = m_pColleageMap.find(name);
    if (ite != m_pColleageMap.end()){
        ite->second->getMessage(msg);
    }
}

Colleage::Colleage(Mediator* pMediator) {
    this->m_pMediator = pMediator;
}

ConcreteColleage::ConcreteColleage(Mediator* pMediator) 
    : Colleage(pMediator) {
    
}

void ConcreteColleage::sendMessage(std::string name,std::string msg) {
    m_pMediator->sendMessage(name,msg);
}

void ConcreteColleage::getMessage(std::string msg) {
    std::cout << "Get Msg: " << msg << std::endl;
}