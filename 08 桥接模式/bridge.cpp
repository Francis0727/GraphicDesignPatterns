#include "bridge.h"

void Linux::installOS() {
    std::cout << "void Linux::installOS()." << std::endl;
}

void Windows::installOS() {
    std::cout << "void Windows::installOS()." << std::endl;
}

Computer::Computer(OS* pOS) {
    this->m_pOS = pOS;
}

AppleComputer::AppleComputer(OS* pOS) : Computer(pOS) {
    
}

void AppleComputer::startInstallOS() {
    m_pOS->installOS();
}

ThinkPadComputer::ThinkPadComputer(OS* pOS) : Computer(pOS) {

}

void ThinkPadComputer::startInstallOS() {
    m_pOS->installOS();
}

