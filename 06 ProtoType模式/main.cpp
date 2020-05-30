#include <iostream>
#include "ProteType.h"

int main(int argc,char** argv) {
	Product* linePen = new UnderlinePen("5","blue");
	Product* box = new MessageBox("12","34");
	Manage* manageInstance = new Manage;
	manageInstance->regester("linePen",linePen);
	manageInstance->regester("box",box);

	Product* linePenBack = manageInstance->create("linePen");
	linePenBack->printInfo();
	Product* messageBox = manageInstance->create("box");
	messageBox->printInfo();

	return 0;
}