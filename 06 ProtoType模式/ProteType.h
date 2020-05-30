#ifndef _PROTOTYPE_H
#define _PROTOTYPE_H

#include <iostream>
#include <string>
#include <map>

class Product{
public:
    virtual void use() = 0;             // 产品功能
    virtual Product* createClone() = 0; // 复制备份
    virtual void printInfo() = 0;
};

class UnderlinePen : public Product {
public:
    virtual void use();
    virtual Product* createClone() ;
    UnderlinePen(std::string lineWidth,std::string lineColor);
    void printInfo();
private:
    std::string m_lineWidth;
    std::string m_lineColor;
};

class MessageBox : public Product {
public:
    virtual void use();
    virtual Product* createClone();
    MessageBox(std::string widthLength,std::string heightLength);
    void printInfo();
private:
    std::string m_widthLength;
    std::string m_heightLength;
};

class Manage{
public:
    void regester(std::string name,Product* proto);
    Product* create(std::string protoName);
private:
    std::map<std::string,Product*> showCase;
};

#endif