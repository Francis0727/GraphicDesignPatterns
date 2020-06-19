#include "Memento.h"

Memento::Memento(int vitality,int attack,int defense) {
    this->m_vitality = vitality;
    this->m_attack = attack;
    this->m_defense = defense;
}

void Caretake::Save(Memento menento) {
    m_vecMemento.push_back(menento);
}

Memento Caretake::Load(int state) {
    return m_vecMemento[state];
}

GameRole::GameRole() {
    this->m_defense = 100;
    this->m_attack = 100;
    this->m_vitality = 100;
}

Memento GameRole::Save() {
    Memento memento(m_vitality,m_attack,m_defense);
    return memento;
}

void GameRole::Load(Memento memento) {
    m_vitality = memento.m_vitality;
    m_defense = memento.m_defense;
    m_attack = memento.m_attack;
}

void GameRole::Show() {
    std::cout << "vitality : " << m_vitality << std::endl;
}

void GameRole::Attack() {
    this->m_attack -= 10; 
    this->m_defense -= 10;
    this->m_vitality -= 10; 
}