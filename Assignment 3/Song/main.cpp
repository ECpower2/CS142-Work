
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

#include "Song.h"
int main() {
    cout << "Beginning Test Driver for Song Class...\n";
    Song song1("Emergency","Icona Pop");
    Song song2("Down the Road","c2c");

    cout << "\nTesting Get and Set Methods:\n";
    song1.set("Lightning Bolt","Jake Bugg");
    cout << "New Title: " << song1.title() << endl;
    cout << "New Artist: " << song1.artist() << endl;

    cout << "\nTesting Input and Output Methods:\n";
    cout << "Please enter a song title and artist:\n";

    cin >> song2;
    cout << song2;

    cout << "\nTesting Compare Method:\n";
    cout << "Comparing the following songs:\n" << song1 << endl << song2 << endl;

    if ( (song1 == song2) == 0 ) cout << "Songs are not equal";
    if ( (song1 == song2) == 1 ) cout << "Songs are equal";

    return 0;
    }
