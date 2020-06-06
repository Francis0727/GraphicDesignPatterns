#include <iostream>
#include "stragegy.h"

int main(int argc,char** argv) {
	Strategy* pStragety = new ConcreteStrageA;
	Context* pContext = new Context(pStragety);
	pContext->doAction();
	// 修改关税的计算策略(注: 新策略为ConcreteStrageB)
	pContext->setStragety(new ConcreteStrageB);
	pContext->doAction();
	
	return 0;
}