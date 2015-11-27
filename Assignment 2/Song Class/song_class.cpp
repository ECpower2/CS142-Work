
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

class Song {
    public:
        void initialize();
        void initialize(const string s_title, const string s_artist);
        void read(istream & in);
        void print(ostream & out) const;
        bool is_equal(Song & song2) const;

    private:
        string title, artist;
    };

inline void Song::initialize() {
    title = "invalid";
    artist = "none";
    }

inline void Song::initialize(const string s_title, const string s_artist) {
    title = s_title;
    artist = s_artist;
    }

inline void Song::read(istream & in) {
    string input_title;
    getline(in,input_title);
    title = input_title;

    string input_artist;
    getline(in,input_artist);
    artist = input_artist;
    }

inline void Song::print(ostream & out) const {
    cout << title << endl;
    cout << artist << endl;
    }

inline bool Song::is_equal(Song & song2) const {
    bool equal_check;

    if (artist.compare(song2.artist) == 0 && title.compare(song2.title) == 0) {
        equal_check = true;
    } else {
        equal_check = false;
    }

    return equal_check;
    }

int main() {
    Song test_song;
    test_song.initialize();

    Song compare_song;
    compare_song.initialize("Back in Black","ACDC");

    cout << "Enter a song title and artist: " << endl;
    test_song.read(cin);

    cout << "You entered the song: " << endl;
    test_song.print(cout);

    cout << "Comparing to: " << endl;
    compare_song.print(cout);

    bool equal_check = test_song.is_equal(compare_song);

    if (equal_check) {
        cout << "These songs are the same song" << endl;
    } else {
        cout << "These songs are not the same song" << endl;
    }

    return 0;
}
