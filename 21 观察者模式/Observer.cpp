#include "Observer.h"

void Subject::attach(Observer* obj) {
    m_observer.push_back(obj);
}

std::string Subject::getState() {
    return m_state;
}

void Subject::setState(std::string state) {
    m_state = state;
}

void Subject::notify() {
    std::list<Observer*>::iterator ite = m_observer.begin();
    for (; ite != m_observer.end(); ++ite){
        (*ite)->update(this);
    }
}

void ConcreteObserverA::update(Subject* pSubject) {
    m_state = pSubject->getState();
    std::cout << "ConcreteObserverA is: " << m_state << std::endl;
}

void ConcreteObserverB::update(Subject* pSubject) {
    m_state = pSubject->getState();
    std::cout << "ConcreteObserverB is: " << m_state << std::endl;
}

