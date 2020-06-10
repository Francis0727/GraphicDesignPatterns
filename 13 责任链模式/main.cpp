#include <iostream>
#include "responsibility.h"

int main(int argc,char** argv) {
	Support* alice = new NoSupport("Alice");
	Support* bob = new LimitSupport("Bob");
	Support* charlie = new OddSupport("Charlie");
	Support* fred = new SpecialSupport("Fred");
	// bob是alice的上级，charlie是bob的上级，以此类推.
	alice->setNext(bob)->setNext(charlie)->setNext(fred)->setNext(NULL);
	alice->approve(750);
	alice->approve(350);
	alice->approve(170);
	
	return 0;
}