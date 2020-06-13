#include "state.h"

State* ConcreteStateA::m_pState = NULL;
State* ConcreteStateB::m_pState = NULL;

State* ConcreteStateA::getInstance() {
    if (m_pState == NULL){
        m_pState = new ConcreteStateA;
    }
    return m_pState;
}

void ConcreteStateA::handle(Context* pContext) {
    std::cout << "void ConcreteStateA::handle(Context*)." << std::endl;
    pContext->changeState(ConcreteStateB::getInstance());
}

State* ConcreteStateB::getInstance() {
    if (m_pState == NULL){
        m_pState = new ConcreteStateB;
    }
    return m_pState;
}

void ConcreteStateB::handle(Context* pContext) {
    std::cout << "void ConcreteStateB::handle(Context*)." << std::endl;
    pContext->changeState(ConcreteStateA::getInstance());
}

void Context::changeState(State* pState) {
    this->m_pStatus = pState;
}

void Context::request() {
    m_pStatus->handle(this);
}

Context::Context() {
    m_pStatus = ConcreteStateA::getInstance();
}

