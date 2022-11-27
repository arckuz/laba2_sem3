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

class Date {
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

	Date sub(Date& date1, Date& date2) {
		Date newDate;
		newDate.SetDay(date1.GetDay());
		newDate.SetWeek(date1.GetWeek());
		newDate.SetMonth(date1.GetMonth());
		newDate.SetYear(date1.GetYear());

		newDate.subYear(date2.GetYear());
		newDate.subMonth(date2.GetMonth());
		newDate.subWeek(date2.GetWeek());
		newDate.subDay(date2.GetDay());
		return newDate;
	}
	Date summ(Date& date1, Date& date2) {
		Date newDate;
		newDate.SetDay(date1.GetDay());
		newDate.SetWeek(date1.GetWeek());
		newDate.SetMonth(date1.GetMonth());
		newDate.SetYear(date1.GetYear());

		newDate.addYear(date2.GetYear());
		newDate.addMonth(date2.GetMonth());
		newDate.addDay(date2.GetDay());
		return newDate;
	}

private:
	int day;
	int week;
	int month;
	int year;
	vector<pair<int, int>> calendar = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30}, {7, 31}, {8,31},{9,30}, {10,31}, {11,30}, {0,31} };
	vector<pair<int, int>>::iterator it = calendar.begin();
};

ostream& operator <<(ostream& os, Date& const city) {
	os << "Your Date is " << city.GetDay() << " day " << city.GetWeek() << " week  " << city.GetMonth() << " month " << city.GetYear() << " year\n";
	return os;
}

istream& operator >> (istream& is, Date& dt)
{
	int d, w, m, y;
	is >> d >> w >> m >> y;
	dt.SetDay(d);
	dt.SetWeek(w);
	dt.SetMonth(m);
	dt.SetYear(y);
	return is;
}

class FunctionPart {
public:
	FunctionPart(char s, double n) {
		sign1 = s;
		number = n;
	}
	double Evaluate(double n) {
		if (sign1 == '+') {
			return n + number;
		}
		else if (sign1 == '-') {
			return n - number;
		}
		else if (sign1 == '*') {
			return n * number;
		}
		else if (sign1 == '/') {
			return n / number;
		}
	}

private:
	char sign1;
	double number;
};

class Function {
public:
	void Add(char s, double n) {
		function.push_back({ s, n });
	}
	double EvaluateFunction(double num) {
		for (auto item : function) {
			num = item.Evaluate(num);
		}
		return num;
	}

private:
	vector<FunctionPart> function;
};

int main()
{
	Date date1, date2, date3;

	cout << "How do you want to enter and output dates?\n";
	cout << "1) Console stream;\n";
	cout << "2) String stream;\n";
	cout << "3) File stream.\n";
	int in;
	cin >> in;

	if (in == 1) {
		cin >> date1;
		cin >> date2;
	}
	if (in == 2) {
		stringstream ss;
		ss << "27 43 10 2022" << "\n";
		ss >> date1;
		ss << "1 2 3 4" << "\n";
		ss >> date2;
	}
	if (in == 3) {
		ifstream in1("C:\\Users\\Arckuz\\Desktop\\input1.txt");
		if (in1.is_open())
		{
			in1 >> date1;
		}
		in1.close();
		ifstream in2("C:\\Users\\Arckuz\\Desktop\\input2.txt");
		if (in2.is_open())
		{
			in2 >> date2;
		}
		in2.close();
	}
	date3 = date1 + date2;
	cout << date3;
	cout << date2;










	Function f;
	Numbers m(2, 5,8);
	f.Add('+', m.first);
	f.Add('+', m.second);
	f.Add('-', m.third);
	cout << f.EvaluateFunction(0);
}