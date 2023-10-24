#include <iostream>
#include <string>

using namespace std;

// Position A: NOT GOOD! Date isn't known here.

class Date {
	int d, m, y;

public:
	// A fully specified date
	Date(int dd, int mm, int yy) : d(dd), m(mm), y (yy) {}

	// The day of the month (1-31)
	int day() const { return d; }

	// The month of the year (1-12)
	int month() const { return m; }

	// The year number
	int year() const { return y; }

// Position B: NOT GOOD! operator<< is an independent function!

};

// Position C: GOOD! operator<< is an independent function!
ostream& operator<< (ostream &s, Date const &d) {
  return s << d.day() << '/' << d.month() << '/' << d.year();
}

// Position D: main should be here so that it knows of Date and op<<

int main() {
  Date date_obj(1,2,2002);
  cout << date_obj << endl;
  return 0;
}
