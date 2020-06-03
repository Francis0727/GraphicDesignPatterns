#include "AbstractFactory.h"

void Tray::add(Item* pItem) {
    m_pItem.push_back(pItem);
    pItem->makeHTML();
}

void Page::add(Item* pItem) {
    pItem->makeHTML();
    m_pItem.push_back(pItem);
}

void ListLink::makeHTML() {
    std::cout << "void ListLink::makeHTML()." << std::endl;
}

void ListTray::makeHTML() {
    std::cout << "void ListTray::makeHTML()." << std::endl;
}

void ListPage::makeHTML() {
    std::cout << "void ListTray::makeHTML()." << std::endl;
}

AbstractFactory* Factory::getInstance() {
    return this;
}

Link* Factory::createLink() {
    return new ListLink;
}

Tray* Factory::createTray() {
    return new ListTray;
}

Page* Factory::createPage() {
    return new ListPage;
}

