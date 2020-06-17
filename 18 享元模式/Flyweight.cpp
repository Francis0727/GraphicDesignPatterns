#include "Flyweight.h"

FlyWeight::FlyWeight(std::string gender,std::string addr) {
    this->m_gender = gender;
    this->m_addr = addr;
}

ConcreteFlyWeight::ConcreteFlyWeight(std::string gender,std::string addr) 
    :FlyWeight(gender,addr){
    
}

void ConcreteFlyWeight::Operator() {
    std::cout << "ConcreteFlyWeight Addr: " << this << std::endl;
}

UnsharedConcreteFlyWeight::UnsharedConcreteFlyWeight(std::string gender,std::string addr):FlyWeight(gender,addr) {
    
}

void UnsharedConcreteFlyWeight::Operator() {
    std::cout << "UnsharedConcreteFlyWeight addr: " << this << std::endl;
}

void FlyWeightFactory::inputStudentInfo(std::string key,int age,std::string gender,std::string addr) {
    FlyWeight* pFlyWeight = getInstance(key,gender,addr);
    stusInfo* pStudent = new stusInfo{age,pFlyWeight};
    m_pStudentInfos.push_back(pStudent);
}

FlyWeight* FlyWeightFactory::getInstance(std::string key,std::string gender,std::string addr) {
    if (key == std::string("local")){
        if (sharedWeight.count(key) == 0){
            FlyWeight* pFlyWeight = new ConcreteFlyWeight(gender,addr);
            sharedWeight.insert(std::pair<std::string,FlyWeight*>(key,pFlyWeight));
        }
        return sharedWeight[key];
    }
    return new UnsharedConcreteFlyWeight(gender,addr);
}

void FlyWeightFactory::print() {
    std::vector<stusInfo*>::iterator ite = m_pStudentInfos.begin();
    for (;ite != m_pStudentInfos.end(); ++ite){
        (*ite)->m_pFlyweight->Operator();
    }
}