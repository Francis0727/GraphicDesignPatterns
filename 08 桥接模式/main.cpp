#include <iostream>
#include "bridge.h"

int main(int argc,char** argv){
	OS* win = new Windows;
	Computer* pc = new AppleComputer(win);
	pc->startInstallOS();

	return 0;
}