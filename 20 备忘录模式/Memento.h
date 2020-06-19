#ifndef _memento_h
#define _memento_h

#include <vector>
#include <iostream>

class Memento{
public:
    Memento(int vitality,int attack,int defense);
public:
    int m_vitality;
    int m_attack;
    int m_defense;
};

class Caretake {
public:
    void Save(Memento menento);
    Memento Load(int state);
private:
    std::vector<Memento> m_vecMemento;
};

class GameRole{
public:
    GameRole();
    Memento Save();
    void Load(Memento memento);
    void Show();
    void Attack();
private:
    int m_vitality;
    int m_attack;
    int m_defense;
};

#endif