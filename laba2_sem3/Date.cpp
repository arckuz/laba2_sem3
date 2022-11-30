#include "Date.h"


	void Date::addDay(int d) {
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
	void Date::addMonth(int m) {
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
	void Date::addWeek(int w) {
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
	void Date::addYear(int y) {
		year += y;
	}

	void Date::subDay(int d) {
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
					it = calendar.end() - 1;
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
			if (month == 0) {
				it = calendar.end() - 1;
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
	void Date::subMonth(int m) {
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
	void Date::subWeek(int w) {
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
	void Date::subYear(int y) {
		year -= y;
	}

	void Date::SetDay(int inc) {
		day = inc;
	}
	void Date::SetWeek(int inc) {
		week = inc;
	}
	void Date::SetMonth(int inc) {
		month = inc;
	}
	void Date::SetYear(int inc) {
		year = inc;
	}

	int Date::GetDay() {
		return day;
	}
	int Date::GetWeek() {
		return week;
	}
	int Date::GetMonth() {
		return month;
	}
	int Date::GetYear() {
		return year;
	}

	Date Date::sub(Date& date1, Date& date2) {
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
	Date Date::summ(Date& date1, Date& date2) {
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