#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string.h>
using std::string;

#include <sstream>
using std::istringstream;

int count_lines(const char * file_name, const char * s)
    {
    ifstream ifs_input(file_name);

    string s_line;
    int line_num = 0;
    int num_occurs = 0;

    for (int line_num = 0; getline(ifs_input, s_line); line_num++) {

        const char * s_line_convert = s_line.c_str();
        char * occurs = strstr(s_line_convert,s);

        if(occurs != NULL)
            {
            num_occurs++;
            }
        }

    return num_occurs;
    }

int main()
    {
    const char * file = "test_doc.txt";
    const char * substring = "green";

    int occurrences = count_lines(file,substring);
    cout << occurrences;

    return 0;
    }
