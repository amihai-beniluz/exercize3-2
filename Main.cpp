//Amihai Beniluz 212402655
//workshop in c++
//exercize 3 section 2
//the program 
#include <iostream>
#include<ctime>
#include "Date.h"
using namespace std;

int main()
{
	cout << "Enter a date\n";
	int d, m, y, o=0;
	char tav;
	cin >> d >> tav >> m >> tav >> y;
	Date d1(d, m, y);
	Date d2(1, 1, 1920);
	d1.print();
	enum option {EXIT=-1,SET=1,ADDPRE,ADDPOST,ADD,BIGGER,SMALLER,EQUALS};
	while (o != -1)
	{
		cout << "Enter an action code\n";
		cin>>o;
		switch (o)
		{
		case EXIT:break;
		case SET:
			cout << "Enter a date\n";
			cin >> d >> tav >> m >> tav >> y;
			d1.setDate(d, m, y);
			d1.print();
			break;
		case ADDPRE: (++d1).print(); break;
		case ADDPOST: d1++.print(); break;
		case ADD: 
			cout << "Enter # days\n";
			cin >> d;
			(d1 += d).print();
			break;
		case BIGGER: 
			cout << "Enter a date\n";
			cin >> d >> tav >> m >> tav >> y;
			d2.setDate(d,m,y);
			cout << (d1>d2 ? "true\n" : "false\n");
			break;
		case SMALLER:
			cout << "Enter a date\n";
			cin >> d >> tav >> m >> tav >> y;
			d2.setDate(d, m, y);
			cout << (d1 < d2 ? "true\n" : "false\n");
			break;
		case EQUALS:
			cout << "Enter a date\n";
			cin >> d >> tav >> m >> tav >> y;
			d2.setDate(d, m, y);
			cout << (d1 == d2 ? "true\n" : "false\n");
			break;
		}
	}

	return 0;
}
