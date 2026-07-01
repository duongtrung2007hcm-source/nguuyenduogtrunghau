#include "khaibao.h"
LibrarySystem::LibrarySystem() : root(nullptr), readerHead(nullptr) {}

BookNode* LibrarySystem::insertBook(BookNode* node, Book b) {
    if (!node) return new BookNode{ b, nullptr, nullptr };
    if (b.ISBN < node->data.ISBN) node->left = insertBook(node->left, b);
    else node->right = insertBook(node->right, b);
    return node;
}

void LibrarySystem::addBook(std::string isbn, std::string title) {
    root = insertBook(root, { isbn, title });
    std::cout << "[LOG] Da them sach: " << title << std::endl;
}

void LibrarySystem::addReader(std::string id, std::string name) {
    ReaderNode* newNode = new ReaderNode{ {id, name}, readerHead };
    readerHead = newNode;
    std::cout << "[LOG] Da them doc gia: " << name << std::endl;
}
void LibrarySystem::inOrder(BookNode* node) {
    if (node != nullptr) {
        inOrder(node->left);
        std::cout << "ISBN: " << node->data.ISBN
            << " | Ten sach: " << node->data.title << std::endl;
        inOrder(node->right); 
    }
}
void LibrarySystem::searchBook(std::string isbn) {
    BookNode* current = root;
    while (current != nullptr) {
        if (isbn == current->data.ISBN) {
            std::cout << "TIM THAY: " << current->data.title << std::endl;
            return;
        }
        current = (isbn < current->data.ISBN) ? current->left : current->right;
    }
    std::cout << "Khong tim thay sach co ISBN: " << isbn << std::endl;
}


BookNode* LibrarySystem::findMin(BookNode* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}

BookNode* LibrarySystem::deleteBook(BookNode* node, std::string isbn) {
    if (node == nullptr) return nullptr;
    if (isbn < node->data.ISBN) node->left = deleteBook(node->left, isbn);
    else if (isbn > node->data.ISBN) node->right = deleteBook(node->right, isbn);
    else {
        
        if (node->left == nullptr) { BookNode* temp = node->right; delete node; return temp; }
        else if (node->right == nullptr) { BookNode* temp = node->left; delete node; return temp; }
        
        BookNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteBook(node->right, temp->data.ISBN);
    }
    return node;
}

void LibrarySystem::removeBook(std::string isbn) {
    root = deleteBook(root, isbn);
    std::cout << "Da xoa sach ISBN: " << isbn << std::endl;
}


// Hàm gọi chính để hiển thị
void LibrarySystem::displayLibrary() {
    if (root == nullptr) {
        std::cout << "Thu vien hien dang trong!" << std::endl;
        return;
    }
    std::cout << "\n--- DANH SACH SACH ---" << std::endl;
    inOrder(root);
}
