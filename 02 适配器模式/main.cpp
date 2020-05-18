#include <iostream>
#include "Adapter.h"

int main(int argc,char** argv) {
	Target* pObject = new Adapter(89,78,83);
	std::cout <<"score: " << pObject->getScoreGrade() << std::endl;
	
	return 0;
}