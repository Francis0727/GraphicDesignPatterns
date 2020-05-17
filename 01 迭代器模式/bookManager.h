#ifndef _BOOKMANAGER_H
#define _BOOKMANAGER_H

#include <string>
#include <vector>

class Book {
public:
	Book(const std::string& name);
	std::string getName();
private:
	std::string m_name;
};

class Iterator{
public:
	virtual bool hasNext() {};
	virtual Book next() {};
};

class Aggregate {
public:
	virtual Iterator* iterator() {};
};

class BookShelf : public Aggregate {
public:
	Iterator* iterator();
	Book getBookAt(int index);
	int getLength();
	void appendBook(Book book);
private:
	std::vector<Book> books;
};

class BookShelfIterator : public Iterator {
public:
	BookShelfIterator(BookShelf* bookshelf);
	virtual bool hasNext();
	Book next();
private:
	int index ;
	BookShelf* m_bookShelf;
};


#endif