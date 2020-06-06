#include <iostream>
#include "composite.h"

int main(int argc,char** argv) {
	Entry* file1 = new File(100);
	Entry* file2 = new File(200);
	Entry* file3 = new File(300);

	Directory* pDir1 = new Directory;
	Directory* pDir2 = new Directory;

	pDir1->add(file1);
	pDir1->add(file2);
	pDir2->add(pDir1);
	pDir2->add(file3);

	std::cout << "Directory size: " << pDir2->getSize() << std::endl;
	return 0;
}