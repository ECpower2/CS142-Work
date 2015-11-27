
#ifndef _Song_h_
#define _Song_h_

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
        friend istream & operator>>(istream & in, Song & s);

        Song() : Song("invalid","none") {}
        Song(string title) : Song(title, "none") {}
        Song(string title, string artist) : title_(title), artist_(artist) {}

        string title() const { return title_; }
        string artist() const { return artist_; }

        void set(const string & new_title, const string & new_artist = 0);

    private:
        string title_;
        string artist_;
    };

inline void Song::set(const string & new_title, const string & new_artist) {
    title_ = new_title;
    artist_ = new_artist;
    }

inline istream & operator>>(istream & in, Song & s) {
    getline(in,s.title_);
    getline(in,s.artist_);
    return in;
    }

inline ostream & operator<<(ostream & out, const Song & s) {
    out << s.title() << "\n";
    out << s.artist() << "\n";
    return out;
    }

inline bool & operator==(const Song & s1,const Song & s2) {
    bool equalCheck = false;
    if (s1.title().compare(s2.title()) == 0) {
        if (s1.artist().compare(s2.artist()) == 0 ) {
            equalCheck = true;
            }
        }
    return equalCheck;
    }

#endif // _Song_h_
