#include <iostream>
#include "FactoryMethod.h"

int main(){
	Factory* pFactory = new IDCardFactory;
	Product* pProduct =  pFactory->Create(std::string("Birthday Card"),std::string("Francis")); 
	std::vector<ProductInfos> infos = pFactory->getFactoryInfos();
	for (auto ite = infos.begin(); ite != infos.end(); ++ite){
		std::cout << "productName: " << ite->productName \
		          << " " << "ownerName: "<< ite->ownerName << std::endl; 
	}
	
	return 0;
}