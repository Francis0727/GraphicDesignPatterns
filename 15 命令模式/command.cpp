#include "command.h"

void SiChuanFoodMaster::doAction() {
    std::cout << "void SiChuanFoodMaster::doAction()." << std::endl;
}

void CantoneseCuisineMaster::doAction() {
    std::cout << "void CantoneseCuisineMaster::doAction()." << std::endl;
}

Command::Command(Master* pMaster) {
    this->m_pMaster = pMaster;
}

CantoneseCuisine::CantoneseCuisine(Master* pMaster):Command(pMaster) {

}

void CantoneseCuisine::cooking() {
    m_pMaster->doAction();
}

SiChuanFood::SiChuanFood(Master* pMaster):Command(pMaster) {

}

void SiChuanFood::cooking() {
    m_pMaster->doAction();
}

void Waiter::setOrder(Command* pCommand) {
    std::cout << "receive a new order." << std::endl;
    m_commands.push_back(pCommand);
}

void Waiter::notify() {
    std::vector<Command*>::iterator ite = m_commands.begin();
    for (; ite != m_commands.end();++ite){
        (*ite)->cooking();
    }
}