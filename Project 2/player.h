#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

class Player {
    public:
        Player() : name_("No Name"),year_of_birth_(0),
                   category_("None"),reg_status_("None") {}
        Player(const std::string & name, const int & year_of_birth,
               const std::string & category, const std::string & reg_status) :
                   name_(name),year_of_birth_(year_of_birth),
                   category_(category),reg_status_(reg_status) {}

        std::string get_name() { return name_; }
        void set_name(std::string name) { name_ = name; }

        int get_year_of_birth() { return year_of_birth_; }
        void set_year_of_birth(int year_of_birth) { year_of_birth_ = year_of_birth; }

        std::string get_category() { return category_; }
        void set_category(std::string category) { category_ = category; }

        std::string get_reg_status() { return reg_status_; }
        void set_reg_status(std::string reg_status) { reg_status_ = reg_status; }

        void calculate_category();

    private:
        std::string name_;
        int year_of_birth_;
        std::string category_; //Might try fancy things with this
        std::string reg_status_;
    };

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

#endif // PLAYER_H_INCLUDED
