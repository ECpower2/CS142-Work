
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

#include "Song.h"
void constructor_test_driver() {
    string title = "";
    string artist = "";

    cout << "Please enter the title of a song:\n";
    getline(cin,title);

    cout << "Please enter the name of the respective artist:\n";
    getline(cin,artist);

    try {
        Song s(title,artist);
        cout << "\nYou entered the song:\n" << s;
        }
    catch (const SongError & e) {
        cout << "Song test driver could not complete\n";
        cout << "("+e.what()+")\n";
        }
    }
