#include <iostream>
#include "bookManager.h"

int main(int argc,char** argv) {
	BookShelf shareBookShelf;
	Book book1();

	shareBookShelf.appendBook(Book("Around the World in 80 days"));
	shareBookShelf.appendBook(Book("Bible"));
	shareBookShelf.appendBook(Book("Daddy-long-Legs"));
	
	Iterator* ite = shareBookShelf.iterator();
	while (ite->hasNext()){
		Book book = ite->next();
		std::cout << "book name: " << book.getName() << std::endl;
	}
	
	return 0;
}