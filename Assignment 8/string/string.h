#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iterator>

class String{
    public:
        String() : characters_({}) {}
        String(char arr[]) { *characters_ = *arr; }
        String(const String & s) {}

        int length();

        void print(std::ostream & out);
        void clear_str(); //"clear" is a special term in C++, using alternate name

        char operator[](int i);

        char* c_str() { return characters_; }

        //String operator+(String & str1, String & str2);

    private:
        char characters_[];

    };

inline int String::length() { //This doesn't like working as a for loop
    int ct = 0;
    while (characters_[ct] != '\0')
        ++ct;

    return ct;

    for (int ct = 0; characters_[ct] != '\0'; ++ct) {
        //Doin' good...
        }
    }

inline void String::print(std::ostream & out) {
    int ct = 0;
    while (characters_[ct] != '\0') {
        out << characters_[ct];
        ++ct;
        }
    }

inline void String::clear_str() {
    characters_[0] = {};
    }

inline char String::operator[](int i) {
    return characters_[i];
    }

inline String operator+(String & str1, String & str2) {

    char * str1_chars = str1.c_str();
    char * str2_chars = str2.c_str();

    int sum_length = str1.length() + str2.length();
    char char_sum[sum_length];

    int index;

    for (index = 0; index < str1.length(); ++index) {
        char_sum[index] = str1_chars[index];
        }

    int holder = index;

    for (index = 0; index < str2.length(); ++index) {
        char_sum[index+holder] = str2_chars[index];
        }

    String result(char_sum);
    return result;

    }

#endif // STRING_H_INCLUDED
