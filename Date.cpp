#include "Date.h"

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
	if (d < 1 || d>30)
	{
		day = 1;
		std::cout << "Error day\n";
	}
	if (m < 1 || m>12)
	{
		month = 1;
		std::cout << "Error month\n";
	}
	if (y < 1920 || y>2099)
	{
		year = 1920;
		std::cout << "Error year\n";
	}
}

Date::Date(const Date &d)
{
	day = d.day;
	month = d.month;
	year=d.year;
}

Date::Date(Date&& d)
{
	Date(d.day, d.month, d.year);
}

void Date::setDate(int d, int m, int y)
{
	if (!(d < 1 || d>30 || m < 1 || m>12 || y < 1920 || y>2099))
	{
		day = d;
		month = m;
		year = y;
	}
}

Date Date::operator++() { // adds 1 (pre)
	day++;
	if (day == 31)
	{
		day = 1;
		month++;
		if (month == 13)
		{
			month = 1;
			year++;
			if (year == 2100)year = 1920;
		}
	}
	return *this;
}

Date Date::operator++(int u) { // adds 1 (post)
	Date temp = *this;
	if (++day == 31)
	{
		day = 1;
		if (++month == 13)
		{
			month = 1;
			if (++year == 2100)year = 1920;
		}
	}
	return temp;
}

Date Date::operator+=(int d) { // adds d (pre)
	this->setDate((day+d)%30 , (month+(day+d)/30)%12 , year+(month+(day+d)/30)/12);
	if ((year + (month + (day + d) / 30) / 12) >= 2100)this->setDate(1,1,1920);
	return *this;
}

bool Date::operator>(Date d)
{
	if (year > d.year)return 1;
	if (month > d.month)return 1;
	if (day > d.day)return 1;
	return 0;
}

bool Date::operator<(Date d)
{
	if (year < d.year)return 1;
	if (month < d.month)return 1;
	if (day < d.day)return 1;
	return 0;
}

bool Date::operator==(Date d)
{
	if (*this<d || *this>d)return 0;
	return 1;
}

void Date::print()
{
	std::cout << day << "/" << month << "/" << year << "\n";
}
