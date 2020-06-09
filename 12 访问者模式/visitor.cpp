#include "visitor.h"

void Entry::Add(Entry* pEntry) {
    throw std::string("void Entry::Add(Entry*).");
}

std::string Entry::getEntryInfo() {
    return getName() +  + "(" + std::to_string(getSize()) + ")" ;
}

File::File(std::string name,int size) {
    this->m_name = name;
    this->m_size = size;
}

std::string File::getName() {
    return this->m_name;
}

int File::getSize() {
    return this->m_size;
}

void File::accept(Visitor* pVisitor) {
    pVisitor->visit(*this);    
}

Directory::Directory(std::string name) {
    this->m_name = name;
}

int Directory::getSize() {
    int size = 0;
    std::vector<Entry*>::iterator ite = m_pVecEntry.begin();
    for (; ite != m_pVecEntry.end(); ++ite){
        size += (*ite)->getSize();
    }
    return size;
}

std::string Directory::getName() {
    return this->m_name;
}

void Directory::accept(Visitor* pVisitor) {
    pVisitor->visit(*this);
}

void Directory::Add(Entry* pEntry) 
{
    m_pVecEntry.push_back(pEntry);
}

void ListVisitor::visit(File& file) {
    std::cout << currentDir << "/" << file.getEntryInfo() << std::endl;
}

void ListVisitor::visit(Directory& directory) {
    std::cout << currentDir << "/" << directory.getEntryInfo() << std::endl;
    std::string saveDir = currentDir;
    currentDir = currentDir + "/" + directory.getName();
    std::vector<Entry*>::iterator ite = directory.m_pVecEntry.begin();
    for (; ite != directory.m_pVecEntry.end();++ite){
        (*ite)->accept(this);
    }
    currentDir = saveDir;
}