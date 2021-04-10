#pragma once
#include<iostream>
class Date
{
	int day;
	int month;
	int year;

public:
	Date(int d=1,int m=1,int y=1920);
	Date(const Date &d);
	Date(Date&& d);
	void setDate(int, int, int);
	Date operator++();
	Date operator++(int);
	Date operator+=(int);
	bool operator>(Date);
	bool operator<(Date);
	bool operator==(Date);
	void print();
};

