#include <iostream>
#include <fstream>
#include <string>

#include "book.h"
#include "book_map.h"

using namespace std;

int main() {
    BookMap library;
    library.read_file("books.txt");

    library.display();

    return 0;
    }
