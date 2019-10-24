#include<iostream>
using namespace std;

class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	~Date() {}
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d) { 
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};