#include "decorator.h"

void ConcreteComponent::Operation() {
    std::cout << "void ConcreteComponent::Operation()." << std::endl;
}

Decorator::Decorator(Component* pComponent) {
    m_pComponent = pComponent;
}

ConcreteDecoratorA::ConcreteDecoratorA(Component* pComponent) 
    : Decorator(pComponent){
    
}

void ConcreteDecoratorA::AddBehavor() {
    std::cout << "########################" << std::endl;
}

void ConcreteDecoratorA::Operation() {
    this->AddBehavor();
    m_pComponent->Operation();
}

ConcreteDecoratorB::ConcreteDecoratorB(Component* pComponent) 
    : Decorator(pComponent){
    
}

void ConcreteDecoratorB::AddBehavor() {
    std::cout << "****************************" << std::endl;
}

void ConcreteDecoratorB::Operation() {
    m_pComponent->Operation();
    this->AddBehavor();
}