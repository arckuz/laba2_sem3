#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

struct DAY {
public:
	int day;
	explicit DAY(int d) {
		day = d;
	}
};
struct WEEK {

	int week;
	explicit WEEK(int n) {
		week = n;
	}
};
struct MONTH {

	int month;
	explicit MONTH(int n) {
		month = n;
	}
};
struct YEAR {

	int year;
	explicit YEAR(int n) {
		year = n;
	}
};


class DATE {
public:

	DATE() {

	}

	DATE(int d, int w, int m, int y) {
		day = d;
		week = w;
		month = m;
		year = y;
	}

	DATE(DAY d, WEEK w, MONTH m, YEAR y) {
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

	

	void addDay(int d) {
		it = calendar.begin();
		while (true) {
			if (it->first != month % 12) {
				it++;
			}
			else {
				break;
			}
		}
		while (d > 0) {
			if (d >= it->second) {
				d -= it->second;
				it++;
				month++;
				if (month > 12) {
					it = calendar.begin();
					month = 1;
					year++;
					if (year % 4 == 0) {
						calendar[1] = make_pair(2, 29);
					}
					else {
						calendar[1] = make_pair(2, 28);
					}
				}
			}
			else { break; }
			
		}
		day += d;
		while (day > it->second) {
			day -= it->second;
			it++;
			month++;
			if (month > 12) {
				it = calendar.begin();
				month = 1;
				year++;
				if (year % 4 == 0) {
					calendar[1] = make_pair(2, 29);
				}
				else {
					calendar[1] = make_pair(2, 28);
				}
			}
		}
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
		if (count / 7 != 0) {
			week = count / 7;
		}
		else {
			week = 1;
		}
	}	
	void addMonth(int m) {
		month += m;
		while (month > 12) {
			month -= 12;
			year++;
		}
		if (year % 4 == 0) {
			calendar[1] = make_pair(2, 29);
		}
		else {
			calendar[1] = make_pair(2, 28);
		}
		it = calendar.begin();
		while (true) {
			if (it->first != month % 12) {
				it++;
			}
			else {
				break;
			}
		}
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
		if (count / 7 != 0) {
			week = count / 7;
		}
		else {
			week = 1;
		}
	}
	void addWeek(int w) {
		w *= 7;
		addDay(w);
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
		if (count / 7 != 0) {
			week = count / 7;
		}
		else {
			week = 1;
		}
	}
	void addYear(int y) {
		year += y;
	}

	void subDay(int d) {
		it = calendar.begin();
		while (true) {
			if (it->first != month % 12) {
				it++;
			}
			else {
				break;
			}
		}
		if (year % 4 == 0) {
			calendar[1] = make_pair(2, 29);
		}
		while (d > 0) {
			if (d >= it->second) {
				d -= it->second;
				int t = it->second;
				month--;
				if (month == 0) {
					it = calendar.end()-1;
					month = 12;
					day += it->second - t;
					year--;
					if (year % 4 == 0) {
						calendar[1] = make_pair(2, 29);
					}
					else {
						calendar[1] = make_pair(2, 28);
					}
				}
				else {
					it--;
					day += it->second - t;
				}
			}
			else { break; }

		}
		day -= d;
		while (day <= 0) {
			day += it->second;
			it--;
			month--;
			if (month == 0 ) {
				it = calendar.end()-1;
				month = 12;
				year--;
				if (year % 4 == 0) {
					calendar[1] = make_pair(2, 29);
				}
				else {
					calendar[1] = make_pair(2, 28);
				}
			}
		}
		if (day > it->second) {
			day -= it->second;
			month++;
		}	
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
		if (count / 7 != 0) {
			week = count / 7;
		}
		else {
			week = 1;
		}
	}
	void subMonth(int m) {
		month -= m;
		while (month <= 0) {
			month += 12;
			year -= 1;
		}
		if (year % 4 == 0) {
			calendar[1] = make_pair(2, 29);
		}
		it = calendar.begin();
		while (true) {
			if (it->first != month % 12) {
				it++;
			}
			else {
				break;
			}
		}
		if (day > it->second) {
			day -= it->second;
			month -= 1;
		}
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
		if (count / 7 != 0) {
			week = count / 7;
		}
		else {
			week = 1;
		}
	}
	void subWeek(int w) {
		w *= 7;
		subDay(w);
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
		if (count / 7 != 0) {
			week = count / 7;
		}
		else {
			week = 1;
		}
	}
	void subYear(int y) {
		year -= y;
	}

	void SetDay(int inc) {
		day = inc;
	}
	void SetWeek(int inc) {
		week = inc;
	}
	void SetMonth(int inc) {
		month = inc;
	}
	void SetYear(int inc) {
		year = inc;
	}

	int GetDay() {
		return day;
	}
	int GetWeek() {
		return week;
	}
	int GetMonth() {
		return month;
	}
	int GetYear() {
		return year;
	}

private:
	int day;
	int week;
	int month;
	int year;
	vector<pair<int, int>> calendar = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30}, {7, 31}, {8,31},{9,30}, {10,31}, {11,30}, {0,31} };
	vector<pair<int, int>>::iterator it = calendar.begin();
};
class ARITHMETIC {
public:
	DATE sub(DATE date1, DATE date2) {
		DATE newDATE;
		newDATE.SetDay(date1.GetDay());
		newDATE.SetWeek(date1.GetWeek());
		newDATE.SetMonth(date1.GetMonth());
		newDATE.SetYear(date1.GetYear());

		newDATE.subYear(date2.GetYear());
		newDATE.subMonth(date2.GetMonth());
		newDATE.subWeek(date2.GetWeek());
		newDATE.subDay(date2.GetDay());
		return newDATE;
	}
	DATE summ(DATE date1, DATE date2) {
		DATE newDATE;
		newDATE.SetDay(date1.GetDay());
		newDATE.SetWeek(date1.GetWeek());
		newDATE.SetMonth(date1.GetMonth());
		newDATE.SetYear(date1.GetYear());

		newDATE.addYear(date2.GetYear());
		newDATE.addMonth(date2.GetMonth());
		newDATE.addDay(date2.GetDay());
		return newDATE;
	}
};

ostream& operator <<(ostream& os, DATE& const city) {
	os << "Your DATE is " << city.GetDay() << " day " << city.GetWeek() << " week  " << city.GetMonth() << " month " << city.GetYear() << " year\n";
	return os;
}

istream& operator >> (istream& is, DATE& dt)
{
	int d, w, m, y;
	is >> d >> w >> m >> y;
	dt.SetDay(d);
	dt.SetWeek(w);
	dt.SetMonth(m);
	dt.SetYear(y);
	return is;
}

int main()
{
	DATE DATE1(1, 1, 1, 1984);
	DATE DATE2;
	//DATE DATE2(1, 1, 1, 2022);
	cout << DATE1 << endl;
	cin >> DATE2;
	cout << DATE2 << endl;
	ARITHMETIC ar;
	//cout << ar.summ(DATE1, DATE2);
	//cout << ar.sub(ar.summ(DATE1, DATE2), DATE1);

}