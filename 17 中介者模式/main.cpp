#include <iostream>
#include "mediator.h"

int main(int argc,char** argv){
	ConcreteMediator* centor = new ConcreteMediator;
	ConcreteColleage* xiaoMing = new ConcreteColleage(centor);
	ConcreteColleage* qingSheng = new ConcreteColleage(centor);
	ConcreteColleage* xiaoZhu = new ConcreteColleage(centor);

	centor->setColleage(std::string("xMing"),xiaoMing);
	centor->setColleage(std::string("qSheng"),qingSheng);
	centor->setColleage(std::string("xZhu"),xiaoZhu);

	xiaoMing->sendMessage(std::string("qSheng"),"hello xiaoZhu");
	qingSheng->sendMessage(std::string("xMing"),"HuoGan");
	
	return 0;
}