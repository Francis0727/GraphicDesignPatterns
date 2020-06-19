#include "Memento.h"

int main(int argc,char** argv){
	Caretake caretake;
	GameRole role;
	role.Show();
	caretake.Save(role.Save());
	role.Attack();   // 发起攻击
	role.Show();

	role.Load(caretake.Load(0));
	role.Show();
	
	return 0;
}