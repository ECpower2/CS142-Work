
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

#include "Song.h"
void input_test_driver() {
    Song s("none","none");

    try {
        cout << "Please enter the title and artist of a song:\n";
        cin >> s;
        cout << "\nYou entered the song:\n" << s;
        }
    catch (const SongError & e) {
        cout << "Song test driver could not complete\n";
        cout << "("+e.what()+")\n";
        }
    }
