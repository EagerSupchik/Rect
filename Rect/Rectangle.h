#pragma once
#include <iostream>

using namespace std;

class RefRec;

class Rectangle1
{
	int x;
	int y;
	int xO;
	int yO;
	bool xb = 0, yb = 0;
	friend RefRec;


	void print()
	{
		for (size_t i = 0; i < yO; i++)
		{
			cout << endl;
		}

		for (size_t i = 0; i < y; i++)
		{
			for (size_t i = 0; i < xO; i++)
			{
				cout << "   ";
			}
			for (size_t j = 0; j < x; j++)
			{
				cout << "#  ";
			}
			cout << endl;
		}
	}

public:

	Rectangle1(int x, int y, int xO, int yO) :x{ x }, y{ y }, xO{ xO }, yO{ yO } {}
	Rectangle1() :Rectangle1(3, 3, 0, 0) {}

	friend ostream& operator << (ostream& ost, Rectangle1& rec) {
		for (size_t i = 0; i < rec.yO; i++)
		{
			ost << endl;
		}

		for (size_t i = 0; i < rec.y; i++)
		{
			for (size_t i = 0; i < rec.xO; i++)
			{
				ost << "   ";
			}
			for (size_t j = 0; j < rec.x; j++)
			{
				ost << "#  ";
			}
			ost << endl;
		}

		return ost;
	}

	friend istream& operator >> (istream& is, Rectangle1& rec)
	{
		cout << "Input x: ";
		is >> rec.x;

		cout << "Input y: ";
		is >> rec.y;

		cout << "Input xO: ";
		is >> rec.xO;

		cout << "Input yO: ";
		is >> rec.yO;

		return is;
	}


	void operator += (int n) {
		x += n;
		y += n;
	}
	void perm(int xO, int yO) {
		this->xO += xO;
		this->yO += yO;
		if (this->xO < 0) {
			this->xO = 0;
		}
		if (this->yO < 0) {
			this->yO = 0;
		}
		if (this->xO >= (10 + x)) {
			xb = !xb;
		}
		if (this->yO >= (10 + y)) {
			yb = !yb;
		}
	}
	void operator()(int xO, int yO) {
		perm(xO, yO);
	}

	void operator()() {
		if (xO == 0) {
			xb = !xb;
		}
		if (yO == 0) {
			yb = !yb;
		}
		if (xb and yb) {
			perm(1, 1);
		}
		else if (!xb and !yb) {
			perm(-1, -1);
		}
		else if (xb) {
			perm(1, -1);
		}
		else {
			perm(-1, 1);
		}
	}

};

class RefRec
{
public:
	Rectangle1 rec;

	void prt()
	{
		rec.print();
	}
};


