#include <iostream>
#include "visitor.h"

int main(int argc,char** argv){
	Directory* rootDir = new Directory("root");
	Directory* binDir = new Directory("bin");
	File* file1 = new File("file1.txt",100);
	File* file2 = new File("file2.txt",200);
	File* file3 = new File("file3.txt",300);
	binDir->Add(file1);
	binDir->Add(file2);
	rootDir->Add(binDir);
	rootDir->Add(file3);
	std::cout << "root size: " << rootDir->getSize() << std::endl;
	std::cout << "----------------------------" << std::endl;
	rootDir->accept(new ListVisitor);
	std::cout << "----------------------------" << std::endl;
	binDir->accept(new ListVisitor);
	return 0;
}