#include "Date.h"

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
	if (in != 1 && in != 2 && in != 3) {
		cout << "Incorrect input";
		return 0;
	}
	date3 = date1 + date2;
	cout << date3;
	cout << date2;


	//Function f;
	//Numbers m(2, 5,8);
	//f.Add('+', m.first);
	//f.Add('+', m.second);
	//f.Add('*', m.third);
	//cout << f.EvaluateFunction(0);
}