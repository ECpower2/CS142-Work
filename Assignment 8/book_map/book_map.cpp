#include "book.h"
#include "book_map.h"

using namespace std;

int main() {
    //Doubles as a test driver for other piece of code in book_map.h
    BookMap library;
    library.read_file("books.txt");

    std::cout << "Printing Library: " << std::endl;
    library.display();

    //Second piece of code - year of publication filter

    std::map<std::string, Book> m = library.get_books();

    std::cout << "Books published since 2005:"  << std::endl;
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        int year = itr->second.year_;
        if (year >= 2005)
            std::cout << itr->second.title_ << std::endl;
        }

    return 0;
    }
