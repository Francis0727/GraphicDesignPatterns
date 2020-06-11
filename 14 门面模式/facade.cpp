#include "facade.h"

void SubSystemA::Operator() {
    std::cout << "void SubSystemA::Operator()." << std::endl;
}

void SubSystemB::Operator() {
    std::cout << "void SubSystemB::Operator()." << std::endl;
}

Facade::Facade() {
    m_pSystemA = new SubSystemA;
    m_pSystemB = new SubSystemB;
}

Facade::~Facade() {
    delete m_pSystemA;
    delete m_pSystemB;
    m_pSystemA = NULL;
    m_pSystemB = NULL;
}

void Facade::OperatorWrapper() {
    m_pSystemA->Operator();
    m_pSystemB->Operator();
}
