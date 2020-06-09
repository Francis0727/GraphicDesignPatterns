#ifndef _VISITOR_H
#define _VISITOR_H

#include <string>
#include <iostream>
#include <vector>
#include "visitor.h"

class Visitor;
class Element {
public:
    virtual void accept(Visitor* pVisitor) = 0;
};

class Entry : public Element {
public:
    virtual std::string getName() = 0;
    virtual int getSize() = 0;
    virtual void Add(Entry* pEntry);
    virtual std::string getEntryInfo(); 
};

class File : public Entry {
public:
    File(std::string name,int size);
    virtual std::string getName();
    virtual int getSize();
    void accept(Visitor* pVisitor);
protected:
    std::string m_name;
    int m_size;
};

class Directory : public Entry {
public:
    Directory(std::string name);
    virtual int getSize();
    virtual std::string getName();
    void accept(Visitor* pVisitor);
    virtual void Add(Entry* pEntry);
public:
    std::vector<Entry*> m_pVecEntry;
    std::string m_name;
};

class Visitor {
public:
    virtual void visit(File& file) {}
    virtual void visit(Directory& directory) {}
};

class ListVisitor : public Visitor {
public:
    virtual void visit(File& file);
    virtual void visit(Directory& directory);
private:
    std::string currentDir;
};
#endif