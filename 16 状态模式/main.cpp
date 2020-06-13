#include <iostream>
#include "state.h"

int main(int argc,char** argv) {
	Context* pContext = new Context;
	// 这是包含状态的，因此每次执行看到的结果都可能不同
	pContext->request();
	pContext->request();
	pContext->request();

	return 0;
}