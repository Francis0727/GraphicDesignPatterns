#ifndef _ABSTRACTFACTORY_H
#define _ABSTRACTFACTORY_H

#include <string>
#include <vector>
#include <iostream>
#include <vector>

// 抽象零件，作为其它零件的基类
class Item{
public:
    virtual void makeHTML() = 0;
};

// 抽象零件
class Link : public Item {
public:
    virtual void makeHTML() = 0;
};

class Tray : public Item {
public:
    virtual void makeHTML() = 0;
    void add(Item* pItem);
protected:
    std::vector<Item*> m_pItem;
};

class Page {
public:
    virtual void makeHTML() = 0;
    void add(Item* pItem);
protected:
    std::vector<Item*> m_pItem;
};

// 定义一个抽象工厂
class AbstractFactory{
public:
    virtual AbstractFactory* getInstance() {return NULL;};
    virtual Link* createLink() { return NULL;};
    virtual Tray* createTray() { return NULL;};
    virtual Page* createPage() { return NULL;};
protected:
    AbstractFactory* m_pFactory;
};

// 实例化的零件
class ListLink : public Link {
public:
    virtual void makeHTML();
};

class ListTray : public Tray {
    virtual void makeHTML();
};

class ListPage : public Page{
    virtual void makeHTML();
};

// 定义一个实体工厂
class Factory : public AbstractFactory {
public:
    virtual AbstractFactory* getInstance();
    virtual Link* createLink();
    virtual Tray* createTray();
    virtual Page* createPage();
};

#endif