#include <iostream>
#include "ProteType.h"

void UnderlinePen::use() {
    std::cout << "void UnderlinePen::use()." << std::endl;
}

Product* UnderlinePen::createClone() {
    UnderlinePen* linePen = new UnderlinePen({this->m_lineWidth,this->m_lineColor});
    return linePen;
}

UnderlinePen::UnderlinePen(std::string lineWidth,std::string lineColor) {
    this->m_lineColor = lineColor;
    this->m_lineWidth = lineWidth;
    std::cout << "UnderlinePen(std::string,std::string)." << std::endl;
}

void UnderlinePen::printInfo() {
    std::cout << "lineColor: " << this->m_lineColor << std::endl;
    std::cout << "lineWidth: " << this->m_lineWidth << std::endl;
}

void MessageBox::use(){
    std::cout <<"void MessageBox::use()." << std::endl;
}

Product* MessageBox::createClone(){
    MessageBox* box = new MessageBox({this->m_widthLength,this->m_heightLength});
    std::cout << "MessageBox::createClone()." << std::endl;
    return box;
}

MessageBox::MessageBox(std::string widthLength,std::string heightLength) {
    this->m_widthLength = widthLength;
    this->m_heightLength = heightLength;
    std::cout << "MessageBox(std::string,std::string)." << std::endl;
}

void MessageBox::printInfo() {
    std::cout << "widthLength: " << m_widthLength << std::endl;
    std::cout << "heightLength: " << m_heightLength << std::endl;
}

void Manage::regester(std::string name,Product* proto) 
{
    showCase.insert(std::make_pair(name,proto));
}

Product* Manage::create(std::string protoName) 
{   
    if (this->showCase.count(protoName)){
        return showCase[protoName];
    }
    else {
        return nullptr;
    }
    
}

