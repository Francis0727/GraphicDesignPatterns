#include <iostream>
#include "AbstractFactory.h"

int main(int argc,char** argv) {
	Factory chinaFactory;
	AbstractFactory* pFactory = chinaFactory.getInstance();

	Link* people = pFactory->createLink();
	Link* yahoo = pFactory->createLink();
	Link* google = pFactory->createLink();
	Link* baidu = pFactory->createLink();
	Tray* japan = pFactory->createTray();

	Tray* china = pFactory->createTray();
	Tray* usa = pFactory->createTray();

	Page* page = pFactory->createPage();

	page->add(china);
	china->add(people);
	china->add(baidu);

	page->add(usa);
	usa->add(japan);
	usa->add(yahoo);
	usa->add(google);


	return 0;
}