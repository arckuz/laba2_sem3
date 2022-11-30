#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;
struct Numbers {
public:
	Numbers(int f, int s, int t) {
		first = f;
		second = s;
		third = t;
	}

	int first;
	int second;
	int third;
};

struct Day {
public:
	int day;
	explicit Day(int d) {
		day = d;
	}
};
struct Week {

	int week;
	explicit Week(int n) {
		week = n;
	}
};
struct Month {

	int month;
	explicit Month(int n) {
		month = n;
	}
};
struct Year {

	int year;
	explicit Year(int n) {
		year = n;
	}
};

class Date
{
public:
	Date() {

	}

	Date(int d, int w, int m, int y) {
		day = d;
		week = w;
		month = m;
		year = y;
	}

	Date(Day d, Week w, Month m, Year y) {
		day = d.day;
		week = w.week;
		month = m.month;
		year = y.year;
	}
	void Convert() {
		int count = 0;

		count += day;
		it = calendar.begin();
		while (it->first != month % 12) {
			it++;
		}

		if (year % 4 == 0) {
			calendar[1] = make_pair(2, 29);
		}
		if (it->first != 1) {
			it--;
			while (true) {
				count += it->second;
				if (it == calendar.begin()) {
					break;
				}
				it--;
			}
		}
		for (int i = 0; i != year; i++) {
			if (i % 4 == 0) {
				count += 366;
			}
			else {
				count += 365;
			}
		}
		cout << count;
	}

	Date operator+(Date& Date2) {
		Date ar1;
		Date date(GetDay(), GetWeek(), GetMonth(), GetYear());
		return ar1.summ(date, Date2);;
	}
	Date operator-(Date& Date2) {
		Date ar1;
		Date date(GetDay(), GetWeek(), GetMonth(), GetYear());
		return ar1.sub(date, Date2);;
	}
	const bool operator == (Date& Date2)
	{
		if (day == Date2.GetDay() && week == Date2.GetWeek() && month == Date2.GetMonth() && year == Date2.GetYear()) {
			return true;
		}
		return false;
	};
	const bool operator > (Date& Date2)
	{
		if (year > Date2.GetYear()) {
			return true;
		}
		else if (year == Date2.GetYear()) {
			if (month > Date2.GetMonth()) {
				return true;
			}
			else if (month == Date2.GetMonth()) {
				if (day > Date2.GetDay()) {
					return true;
				}
			}
		}
		return false;
	};
	const bool operator < (Date& Date2)
	{
		if (year > Date2.GetYear()) {
			return false;
		}
		else if (year == Date2.GetYear()) {
			if (month > Date2.GetMonth()) {
				return false;
			}
			else if (month == Date2.GetMonth()) {
				if (day > Date2.GetDay()) {
					return false;
				}
			}
		}
		return true;
	};


	void addDay(int d);
	void addMonth(int m);
	void addYear(int y);
	void addWeek(int w);

	void subDay(int d);
	void subMonth(int m);
	
	void subWeek(int w);
	
	void subYear(int y);

	void SetDay(int inc);
	void SetWeek(int inc);
	void SetMonth(int inc);
	void SetYear(int inc);

	int GetDay();
	int GetWeek();
	int GetMonth();
	int GetYear();

	Date sub(Date& date1, Date& date2);
	Date summ(Date& date1, Date& date2);

private:
	int day;
	int week;
	int month;
	int year;
	vector<pair<int, int>> calendar = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30}, {7, 31}, {8,31},{9,30}, {10,31}, {11,30}, {0,31} };
	vector<pair<int, int>>::iterator it = calendar.begin();
};



