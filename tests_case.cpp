#include "khaibao.h" 
#include <cassert>
void test_AllFunctions() {
    LibrarySystem lib;

    std::cout << "Dang test: Them sach..." << std::endl;
    lib.addBook("ISBN_01", "Lap Trinh C++");
    lib.addBook("ISBN_02", "Cau Truc Du Lieu Va Giai Thuat");
    std::cout << " Them sach xong!" << std::endl;

    
    std::cout << "Dang test: Tim kiem..." << std::endl;
    lib.searchBook("ISBN_01"); 
    std::cout << " Tim kiem xong!" << std::endl;

  
    std::cout << "Dang test: Xoa sach..." << std::endl;
    lib.removeBook("ISBN_01");
    std::cout << " Xoa sach xong!" << std::endl;

    std::cout << "Dang test: Them doc gia..." << std::endl;
    lib.addReader("RD01", "Nguyen Van A");
    assert(lib.readerHead != nullptr); 
    std::cout << " Them doc gia xong!" << std::endl;
}

int main() {
    test_AllFunctions();
    std::cout << "\nTat ca cac Test Case deu vuot qua!" << std::endl;
    return 0;
}
