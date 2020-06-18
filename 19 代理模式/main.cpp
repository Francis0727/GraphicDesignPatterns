#include <iostream>
#include "Proxy.h"

int main(int argc,char** argv){
	Subject* pSubject = new Proxy;
	pSubject->request();
	
	return 0;
}