#include <iostream>
#include "Flyweight.h"

int main(int argc,char** argv){
	FlyWeightFactory* pFlyFactory = new FlyWeightFactory;
	std::string nonlocal = " nonlocal";
	std::string local = "local";

	pFlyFactory->inputStudentInfo(local,29,"Boy","JIAN");
	pFlyFactory->inputStudentInfo(local,27,"Boy","JIAN");
	pFlyFactory->inputStudentInfo(nonlocal,26,"Girl","YongXin");
	pFlyFactory->print();
	
	return 0;
}