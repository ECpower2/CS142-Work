#ifndef BOOK_MAP_H_INCLUDED
#define BOOK_MAP_H_INCLUDED

#include <map>
#include <iterator>
#include <iostream>
#include <fstream>

#include "book.h"

class BookMap {
    public:
        BookMap() : current_entry(m_books.end()) {}

        void read_file(const std::string & file_name);
        void display();
        void display_current_entry();

        void add_book(Book & b);
        void set_books(std::map<std::string, Book> & m) { m_books = m; }
        std::map<std::string, Book> get_books() { return m_books; }


    private:
        std::map<std::string, Book> m_books;
        std::map<std::string, Book>::iterator current_entry;

    };

inline void BookMap::add_book(Book & b) {
    std::map<std::string, Book> books(get_books());
    books.insert(std::pair<std::string,Book>(b.title_,b));
    set_books(books);
    }

inline void BookMap::display() {
    for (current_entry = m_books.begin(); current_entry != m_books.end(); ++current_entry)
        std::cout << current_entry->second;
    }

inline void BookMap::display_current_entry() {
    std::cout << current_entry->second;
    }

//CODE THAT READS DATA TO FILE
inline void BookMap::read_file(const std::string & file_name) {
    std::ifstream ifs(file_name);
    if (!ifs) return; // no file; one will be created when
        // write_file is called

    Book holder;
    while (!ifs.eof()) {
        ifs >> holder;
        add_book(holder);
        }

    ifs.close();
    }


#endif // BOOK_MAP_H_INCLUDED
