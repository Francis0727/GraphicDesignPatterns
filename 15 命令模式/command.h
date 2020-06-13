#ifndef _COMMAND_H
#define _COMMAND_H

#include <iostream>
#include <vector>
#include <typeinfo>

class Master{
public:
    virtual void doAction() = 0;
};

class SiChuanFoodMaster : public Master{
public:
    virtual void doAction();
};

class CantoneseCuisineMaster : public Master {
public:
    virtual void doAction();
};

class Command{
public:
    Command(Master* pMaster);
    virtual void cooking() = 0;
protected:
    Master* m_pMaster;
};

class CantoneseCuisine : public Command{
public:
    CantoneseCuisine(Master* pMaster);
    virtual void cooking();
};

class SiChuanFood : public Command {
public:
    SiChuanFood(Master* pMaster);
    virtual void cooking();
};

class Waiter {
public:
    void setOrder(Command* pCommand);
    void notify();
protected:
    std::vector<Command*>  m_commands;
};

#endif