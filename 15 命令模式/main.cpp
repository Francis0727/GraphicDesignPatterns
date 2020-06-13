#include <iostream>
#include "command.h"

int main(int argc,char** argv){
	// 生成菜馆里不同菜味风格的厨师
	Master* siChuanMaster = new SiChuanFoodMaster;
	Master* cantoneseMaster = new CantoneseCuisineMaster;
	// 客户在菜馆里面定制的两道菜
	Command* siChuanFood = new SiChuanFood(siChuanMaster);
	Command* cantoneseFood = new CantoneseCuisine(cantoneseMaster);
	// 服务员记录客户点的菜
	Waiter* waiter = new Waiter;
	waiter->setOrder(siChuanFood);
	waiter->setOrder(cantoneseFood);
	// 服务员通知厨师开始做菜
	waiter->notify();

	return 0;
}