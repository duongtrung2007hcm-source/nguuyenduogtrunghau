#include "khaibao.h"
int main() {
    LibrarySystem myLibrary;
    int choice;
    std::string isbn, title, id, name;

    while (true) {
        std::cout << "\n===== QUAN LY THU VIEN =====" << std::endl;
        std::cout << "1. Them sach moi" << std::endl;
        std::cout << "2. Them doc gia" << std::endl;
        std::cout << "3. Tim kiem sach" << std::endl;  // Case 3
        std::cout << "4. Xoa sach" << std::endl;       // Case 4
        std::cout << "5. Hien thi danh sach" << std::endl; // Case 5
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Nhap lua chon: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
        case 1:
            std::cout << "ISBN: "; std::cin >> isbn;
            std::cout << "Ten sach: "; std::cin.ignore(); std::getline(std::cin, title);
            myLibrary.addBook(isbn, title);
            break;
        case 2:
            std::cout << "ID: "; std::cin >> id;
            std::cout << "Ten: "; std::cin.ignore(); std::getline(std::cin, name);
            myLibrary.addReader(id, name);
            break;
        case 3: {
            std::cout << "Nhap ISBN can tim: "; std::cin >> isbn;
            myLibrary.searchBook(isbn);
            break;
        }
        case 4: {
            std::cout << "Nhap ISBN can xoa: "; std::cin >> isbn;
            myLibrary.removeBook(isbn);
            break;
        }
        case 5:
            myLibrary.displayLibrary();
            break;

        default:
            std::cout << "Lua chon khong hop le!" << std::endl;
        }
    }
    return 0;
}
