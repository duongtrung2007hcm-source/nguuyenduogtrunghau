#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <iostream>

struct Book { std::string ISBN, title; };
struct BookNode { Book data; BookNode* left, * right; };

struct Reader { std::string id, name; };
struct ReaderNode { Reader data; ReaderNode* next; };

// Khai báo lớp
class LibrarySystem {
public:
    BookNode* root;
    ReaderNode* readerHead;

    LibrarySystem();
    void addBook(std::string isbn, std::string title);
    void addReader(std::string id, std::string name);
    void displayLibrary(); 
    void inOrder(BookNode* node);
    void searchBook(std::string isbn);
    void removeBook(std::string isbn);
    BookNode* findMin(BookNode* node);
    BookNode* insertBook(BookNode* node, Book b);
    BookNode* deleteBook(BookNode* node, std::string isbn);

};

#endif

