﻿#include "Rectangle.h"
#include <Windows.h>

class Point2;

class Point {
	int x = 6;
	friend Point2;

	void print() {
		cout << x << endl;
	}
	friend void sum(Point2& point2, int i);
	friend void operator +=(Point2& point2, int n);
public:
	operator double() {
		return (double)(x + 10);
	}
	operator bool() {
		return true;
	}

};

class Point2 {
	Point point;
public:
	void print() {
		point.print();
	}
	void print2() {
		cout << point.x << endl;
	}
	friend void sum(Point2& point2, int i);
	friend void operator +=(Point2& point2, int n);
};

void sum(Point2& point2, int i) {
	point2.point.x += i;
}

void operator +=(Point2& point2, int n) {
	point2.point.x += n;
}



int main()
{
	RefRec ref;
	cin >> ref.rec;
	while (true)
	{
		system("cls");
		ref.prt();
		ref.rec();
		Sleep(500);
	}

}