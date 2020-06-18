#include "Proxy.h"

void ConcreteSubject::request() {
    std::cout << "void ConcreteSubject::request()." << std::endl;
}

Proxy::Proxy() {
    m_pSubject = new ConcreteSubject;
}

Proxy::~Proxy() {
    delete m_pSubject;
    m_pSubject = NULL;
}

void Proxy::doSomething(void) {
    std::cout << "void Proxy::doSomething(void)." << std::endl;
}

void Proxy::request() {
    doSomething();
    m_pSubject->request();
}

