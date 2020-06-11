#include <iostream>
#include "facade.h"

int main(int argc,char** argv) {
	Facade* pFacade = new Facade;
	pFacade->OperatorWrapper();
	
	return 0;
}