#include <iostream>
#include "bookManager.h"

Book::Book(const std::string& name){
    this->m_name = name;
}

std::string Book::getName(){
    return this->m_name;
}

Book BookShelf::getBookAt(int index){
    return this->books[index];
}

int BookShelf::getLength(){
    return this->books.size();
}

Iterator* BookShelf::iterator(){
    return new BookShelfIterator(this);
}

void BookShelf::appendBook(Book book){
    this->books.push_back(book);
}

BookShelfIterator::BookShelfIterator(BookShelf* bookshelf){
    this->m_bookShelf = bookshelf;
    this->index = 0;
}

bool BookShelfIterator::hasNext(){
    bool ret = index < m_bookShelf->getLength() ? true : false ;
    return ret;
}

Book BookShelfIterator::next(){
    Book book = m_bookShelf->getBookAt(index);
    ++index;
    return book;
}