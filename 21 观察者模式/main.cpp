#include "Observer.h"

int main(int argc,char** argv){
	// 订阅者
	Observer* observerA = new ConcreteObserverA;
	Observer* observerB = new ConcreteObserverB;
	// 订阅主题,并为主题添加订阅者
	Subject* pSubject  = new ConcreteSubjectA;
	pSubject->attach(observerA);
	pSubject->attach(observerB);
	pSubject->setState("hello world.");
	pSubject->notify();
	
	return 0;
}