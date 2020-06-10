#include "responsibility.h"

Support::Support(std::string name) {
    this->m_name = name;
}

Support* Support::setNext(Support* nextSupport) {
    this->m_nextSupport = nextSupport;
    return nextSupport;
}

bool Support::resolve(double money) {
    return false;
}

void Support::approve(double amountMoney) {
    if (resolve(amountMoney)){
        std::cout << "申报已被" << m_name << "审批" << std::endl;
    }
    // 若自己无权审批，则通知自己的上司进行审批
    else if(NULL != m_nextSupport){
        m_nextSupport->approve(amountMoney);
    }
    else {
        std::cout << "提交审批金额过大,已被拒绝." << std::endl;
    }
}

NoSupport::NoSupport(std::string name) : Support(name) {
    
}

bool NoSupport::resolve(double money) {
    if (money < 100){
        return true;
    }else {
        return false;
    }
}

LimitSupport::LimitSupport(std::string name):Support(name) {
    
}

bool LimitSupport::resolve(double money) {
    if (money < 200){
        return true;
    }else {
        return false;
    }
}

OddSupport::OddSupport(std::string name):Support(name){
    
}

bool OddSupport::resolve(double money) {
    if (money < 500){
        return true;
    }else {
        return false;
    }
}

SpecialSupport::SpecialSupport(std::string name):Support(name) {
    
}

bool SpecialSupport::resolve(double money) {
    if (money < 1000){
        return true;
    }else {
        return false;
    }
}