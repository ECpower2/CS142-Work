// Time class
// Version 1.1
//
// New in this version: long methods moved out of the class
// declaration and declared as inline as appropriate.

#include <iostream>
using std::cout;
using std::cin;
using std::istream;
using std::ostream;

class Time {
    public:
        void initialize() { hours = minutes = 99; }
        void initialize(int h, int m);
        void read(istream & in);
        void print(ostream & out) const;
        void print12(ostream & out) const;
        double minus(const Time & t2) const;

private:
    int hours, minutes;
};

inline void Time::initialize(int h, int m) {
    hours = h;
    minutes = m;
    }

inline void Time::read(istream & in) {
    in >> hours;
    in.get(); // colon
    in>> minutes;
    }

inline void Time::print(ostream & out) const {
    out << hours << ':';
    if (minutes < 10) out << 0;
    out << minutes;
    }

inline void Time::print12(ostream & out) const {
    if (hours == 0) out << 12;
    else if (hours > 12) out << (hours - 12);
    else out << hours;

    out << ':';

    if (minutes < 10) out << 0;
    out << minutes;

    if (hours < 12) out << " a.m.";
    else out << " p.m.";
    }

inline double Time::minus(const Time & t2) const {
    return (hours + minutes/60.0) -
        (t2.hours + t2.minutes/60.0);
    }

void println(const Time & t, ostream & out) {
    t.print(out);
    out << '\n';
    }

int main() {
    Time t1;
    Time t2;
    t1.initialize();
    t2.initialize();

    cout << "Enter two times (24-Hour Format): ";
    t1.read(cin);
    t2.read(cin);

    cout << "Initial Values: \n" ;

    t1.print(cout);
    cout << "  (12-Hour Format: ";
    t1.print12(cout);
    cout << ")\n";

    t2.print(cout);
    cout << "  (12-Hour Format: ";
    t2.print12(cout);
    cout << ")\n";

    cout << "The difference between ";
    t1.print(cout);
    cout << " and ";
    t2.print(cout);
    cout << " is " << t2.minus(t1) << " hours.";

    return 0;
    }
