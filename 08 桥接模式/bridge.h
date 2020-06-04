#ifndef _BRIDGE_H
#define _BRIDGE_H

#include <iostream>

class OS {
public:
    virtual void installOS() = 0;
};

class Linux : public OS {
public:
    virtual void installOS();
};

class Windows : public OS {
public:
    virtual void installOS();
};

class Computer{
public:
    Computer(OS* pOS);
    virtual void startInstallOS() {}
protected:
    OS* m_pOS;
};

class AppleComputer : public Computer{
public:
    AppleComputer(OS* pOS);
    virtual void startInstallOS();
};

class ThinkPadComputer : public Computer {
public:
    ThinkPadComputer(OS* pOS);
    virtual void startInstallOS();
};

#endif