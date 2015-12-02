// Pay calculator
// Version 1

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

#include <iomanip>
using std::fixed;
using std::setprecision;

// using namespace std;

const double kPayRate = 12.0;
const double kOvertimeBonus = 5.0;

struct Time
{
    int hours;
    int minutes;
};

void initialize(Time & t)
{
    t.hours = t.minutes = 99;
}

// Added Code - Alternate Initialize Function
void initialize(Time & t,const int h, const int m)
{
    t.hours = h;
    t.minutes = m;
}
// End of Added Code

void read(Time & t, istream & in)
{
    in >> t.hours;
    in.get(); // colon
    in >> t.minutes;
}

void print(const Time & t, ostream & out)
{
    out << t.hours << ':';
    if (t.minutes < 10) out << '0';
    out << t.minutes;
}

// Added Code - 12-Hour Clock Print Function
void print12(const Time & t, ostream & out)
{
    if(t.hours == 0) out << '12';
    else if (t.hours > 12) out << (t.hours - 12);
    else out << t.hours;
    out << ':';

    if (t.minutes < 10) out << '0';
    out << t.minutes;
}
// End of Added Code

double difference(const Time & t1, const Time & t2) {
    return (t1.hours + t1.minutes/60.0) -
        (t2.hours + t2.minutes/60.0);
}

bool is_before(const Time & t1,const Time & t2) {
    cout << "Before Check: " << difference(t1,t2) << endl;
    if ( difference(t1,t2) < 0 ) {
        return true;
    } else {
        return false;
    }
}

bool is_between(const Time & t1, const Time & t2, const Time & t3) {
    cout << "Between Check: " << difference(t1,t2) << endl;
    cout << difference(t2,t3) << endl;
    if ( difference(t2,t1) >= 0 && difference(t2,t3) < 0 ) {
        return true;
    } else {
        return false;
    }
}

bool is_after(const Time & t1,const Time & t2) {
    cout << "After Check: " << difference(t1,t2) << endl;
    if ( difference(t1,t2) >= 0 ) {
        return true;
    } else {
        return false;
    }
}

double calculate_pay(const Time & start_time, const Time & stop_time, const double pay_rate, const double overtime_bonus) {
    double pay = 0;

    Time six_am;
    initialize(six_am,6,0);
    Time six_pm;
    initialize(six_pm,18,0);

    if ( is_before(start_time,six_am) && is_before(stop_time,six_am) ) {
        pay = (difference(stop_time,start_time) * (pay_rate + overtime_bonus));
    } else if ( is_before(start_time,six_am) && is_between(six_am,stop_time,six_pm) ) {
        pay = (difference(six_am,start_time) * (pay_rate + overtime_bonus))
                + (difference(stop_time,six_am) * pay_rate);
    } else if ( is_before(start_time,six_am) && is_after(stop_time,six_pm) ) {
        pay = (difference(six_am,start_time) * (pay_rate + overtime_bonus))
                + (difference(six_pm,six_am) * pay_rate)
                + (difference(stop_time,six_pm) * (pay_rate + overtime_bonus));
    } else if ( is_between(six_am,start_time,six_pm) && is_between(six_am,stop_time,six_pm) ) {
        pay = (difference(stop_time,start_time) * pay_rate);
    } else if ( is_between(six_am,start_time,six_pm) && is_after(stop_time,six_pm) ) {
        pay = (difference(six_pm,start_time) * pay_rate)
                + (difference(stop_time,six_pm) * (pay_rate + overtime_bonus));
    } else if ( is_after(start_time,six_pm) && is_after(stop_time,six_pm) ) {
        pay = (difference(stop_time,start_time) * (pay_rate + overtime_bonus));
    } else {
        pay = -1;
    }

    return pay;

}


int main()
{
    cout << "Name of input file: ";
    string input_file_name;
    getline(cin, input_file_name);

    ifstream ifs_input(input_file_name.c_str()); // Code would not build without addition of ".c_str()"
    if (!ifs_input) {
        cout << "Could not open file.\n";
        return 1;
    }

    cout << "Name of output file: ";
    string output_file_name;
    getline(cin, output_file_name);

    ofstream ofs_output(output_file_name.c_str()); // Code would not build without addition of ".c_str()"
    if (!ofs_output) {
        cout << "Could not open output file.\n";
        return 1;
    }

    int employee_number;
    while (ifs_input >> employee_number) {
        Time start_time;
        read(start_time, ifs_input);
        Time stop_time;
        read(stop_time, ifs_input);

        double pay = calculate_pay(start_time,stop_time,kPayRate,kOvertimeBonus);

        cout << pay << endl;

        ofs_output << employee_number << ' ';
        print(start_time, ofs_output);
        ofs_output << ' ';
        print(stop_time, ofs_output);
        ofs_output << " $" << fixed << setprecision(2) << pay
                   << endl;
    }

    return 0;
}








