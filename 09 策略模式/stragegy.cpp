#include "stragegy.h"

void ConcreteStrageA::Tax() {
    std::cout << "void ConcreteStrageA::Tax()." << std::endl;
}

void ConcreteStrageB::Tax() {
    std::cout << "void ConcreteStrageB::Tax()." << std::endl;
}

Context::Context(Strategy* pStrategy) {
    this->m_pStrategy = pStrategy;
}

void Context::doAction() {
    m_pStrategy->Tax();
}

void Context::setStragety(Strategy* pStragety) {
    m_pStrategy = pStragety;
}
