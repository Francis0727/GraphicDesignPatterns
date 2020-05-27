#include "FactoryMethod.h"

IDCare::IDCare(std::string productName, std::string ownerName)
{
    this->m_productName = productName;
    this->m_ownerName = ownerName;
    std::cout << "IDCare(std::string,std::string)." << std::endl;
}

void IDCare::use()
{
    std::cout << "void IDCare::use()." << std::endl;
}

ProductInfos IDCare::GetProductInfos()
{
    ProductInfos info;
    info.ownerName = this->m_ownerName;
    info.productName = this->m_productName;
    return info;
}

Product *Factory::Create(std::string productName, std::string ownerName)
{
    Product *pProduct = CreateProduct(productName, ownerName);
    registerProduct(pProduct);
    return pProduct;
}

Product *IDCardFactory::CreateProduct(std::string productName, std::string ownerName)
{
    return new IDCare(productName, ownerName);
}

std::vector<ProductInfos> IDCardFactory::getFactoryInfos()
{
    return this->m_productInfos;
}

void IDCardFactory::registerProduct(Product *pProduct)
{
    ProductInfos productInfo = pProduct->GetProductInfos();
    this->m_productInfos.push_back(productInfo);
}