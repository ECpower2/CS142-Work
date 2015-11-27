#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

class Book {
    public:
        Book() : title_("No Title"),authors_("None"),year_(0) {}
        Book(const std::string & title,
             const std::string & authors,
             const int & year) :
                 title_(title),authors_(authors),year_(year) {}

        std::string title_;
        std::string authors_;
        int year_;
    };

inline std::istream & operator>>(std::istream & in, Book & b) {
    getline(in,b.title_);
    getline(in,b.authors_);
    std::string year;
    getline(in,year);
    b.year_ = std::atoi(year.c_str());

    return in;
    }

inline std::ostream & operator<<(std::ostream & out, const Book & b) {
    out << b.title_ << std::endl << b.authors_ << std::endl << b.year_ << std::endl;
    return out;
    }


#endif // BOOK_H_INCLUDED
