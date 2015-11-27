
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

struct Song { string title, artist; };

void initialize(Song & s) {
    s.title = "invalid";
    s.artist = "none";
}

void initialize(Song & s, const string title, const string artist) {
    s.title = title;
    s.artist = artist;
}

void print(Song & s) {
    cout << s.title << endl;
    cout << s.artist << endl;
}

void read(Song & s, istream & in) {
    string song_title;
    getline(in,song_title);
    s.title = song_title;

    string song_artist;
    getline(in,song_artist);
    s.artist = song_artist;
}

bool is_equal(Song & s1, Song & s2) {
    if ((s1.artist).compare(s2.artist) == 0 && (s1.title).compare(s2.title) == 0) {
        return true;
    } else {
        return false;
    }

}

int main()
{
    Song test_song;
    initialize(test_song);

    Song compare_song;
    initialize(compare_song);

    cout << "Enter a song title and artist: " << endl;
    read(test_song,cin);

    cout << "You entered the song: " << endl;
    print(test_song);

    cout << "Comparing to: " << endl;
    print(compare_song);

    bool equal_check = is_equal(test_song,compare_song);

    if (equal_check) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
