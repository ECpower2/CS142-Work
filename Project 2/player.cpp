#include "player.h"
#include <iostream>
#include <string>
#include <cstdlib>

inline std::istream & operator>>(std::istream & in, Player & p) {
    std::string name,year_of_birth,category,reg_status;

    getline(in,name);
    getline(in,year_of_birth);
    getline(in,category);
    getline(in,reg_status);

    p.set_name(name);
    p.set_year_of_birth(std::atoi(year_of_birth.c_str()));
    p.set_category(category);
    p.set_reg_status(reg_status);

    return in;
    }

inline std::ostream & operator<<(std::ostream & out, Player & p) {
    out << p.get_name() << std::endl;
    out << p.get_year_of_birth() << std::endl;
    out << p.get_category() << std::endl;
    out << p.get_reg_status() << std::endl;

    return out;
    }
