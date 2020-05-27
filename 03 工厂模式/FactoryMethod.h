#ifndef _FACTORYMETHOD_H
#define _FACTORYMETHOD_H

#include <string>
#include <iostream>
#include <vector>

typedef struct {
    std::string productName;
    std::string ownerName;
}ProductInfos;

class Product {
public:
    virtual void use() = 0;   // 产品的功能
    virtual ProductInfos GetProductInfos() = 0;
};

class  IDCare : public Product {
private:
    std::string m_productName;
    std::string m_ownerName;
public:
    IDCare(std::string productName,std::string ownerName);
    virtual void use();
    virtual ProductInfos GetProductInfos();
};

class Factory{
public:
    Product* Create(std::string productName,std::string ownerName);
    virtual void registerProduct(Product* pProduct) = 0;
    virtual Product* CreateProduct(std::string productName,std::string ownerName) = 0;
    virtual std::vector<ProductInfos> getFactoryInfos() = 0;
};

class IDCardFactory : public Factory {
private:
    std::vector<ProductInfos> m_productInfos;
public:
    virtual void registerProduct(Product* pProduct);
    virtual Product* CreateProduct(std::string productName,std::string ownerName);
    virtual std::vector<ProductInfos> getFactoryInfos();
};

#endif