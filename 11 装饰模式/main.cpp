#include <iostream>
#include "decorator.h"

int main(int argc,char** argv){
	// 对ConcreteComponent对象进行修饰
	// 修饰功能: 打印原内容时，先打印""############"字符串
	std::cout << "---------------------------" << std::endl;
	Component* pDecorator = new ConcreteDecoratorA(new ConcreteComponent);
	pDecorator->Operation();
	std::cout << "---------------------------" << std::endl;
	// 经过二次封装，实现在打印内容后输出""****************"字符串
	Component* pDecSecond = new ConcreteDecoratorB(pDecorator);
	pDecSecond->Operation();
	std::cout << "---------------------------" << std::endl;
	Component* pThird = new ConcreteDecoratorA(pDecSecond);
	pThird->Operation();

	return 0;
}