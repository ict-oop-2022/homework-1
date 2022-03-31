
// 
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"

// first HW.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;
const double PI = 3.141592653589793238463;
#include <math.h>
class point
{
public:
	point() {}
	point(float a, float b) :x(a), y(b) {}
	~point() {}
	point& operator=(const point& object)
	{
		x = object.x;
		y = object.y;
		return *this;
	}

	//конструктор копирования?
	point(const point& object)
	{
		x = object.x;
		y = object.y;
	}

	friend ostream& operator << (ostream& stream, point& obj)
	{
		stream << '(' << obj.x << ',' << obj.y << ')';
		return stream;
	}
	float x = 0, y = 0;
};

inline bool operator==(const point& object1, const point& object2)
{
	return (object1.x == object2.x && object1.y == object2.y);
}



//returns distance between points
inline float distance(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

class polyline
{
public:
	polyline() {}
	~polyline() {}

	//конструктор копирования?
	polyline(const polyline& p)
	{
		coords = p.get_coords();
	}

	//adds new point in the end of line
	void push_back(float xp, float yp)
	{
		coords.push_back(point(xp, yp));
	}

	//adds new point in the end of line
	void push_back(point p)
	{
		coords.push_back(p);
	}

	//returns number of points
	int getlen() const
	{
		return coords.size();
	}

	//returns point by index
	point& operator[](int i)
	{
		return coords[i];
	}

	//returns array of points
	const  vector <point>  get_coords() const {
		return coords;
	}

	polyline& operator=(const polyline& object)
	{
		coords = object.coords;
		return *this;

	}

	friend ostream& operator << (ostream& stream, polyline& obj)
	{
		for (auto a : obj.coords)
			stream << a << endl;
		return stream;
	}

	//return perimetr :D
	float get_perimetr() const
	{
		int len = this->getlen();
		if (len == 0 || len == 1)
			return 0;

		float summ = 0;

		for (int i = 1; i < len; i++)
		{
			summ += distance(coords[i], coords[i - 1]);
		}
		return summ;
	}

	//really removes coords
	void clear_coords()
	{
		coords.clear();
	}
private:
	vector <point> coords;

};

class closed_polyline :public polyline {
public:
	float get_perimetr()
	{
		float s= (this->polyline::get_perimetr() + distance((*this)[0], (*this)[(*this).getlen() - 1]));
		return s > 0 ? s : -s;
	}
};//closed_polyline

//check parallelism of 2 lines
inline bool is_parallel(point a1, point a2, point b1, point b2)
{
	return ((a2.y - a1.y) * (b2.x - b1.x) == (b2.y - b1.y) * (a2.x - a1.x));
}

class  polygon :public closed_polyline
{

public:
	//count area of any polygon
	float get_area() //Gauss formula
	{
		vector <point> coords = get_coords();//so so 
		int n = this->getlen();
		float s = 0;

		for (int i = 0; i < n - 1; i++)
		{
			s += (*this)[i].x * (*this)[i + 1].y - (*this)[i + 1].x * (*this)[i].y;
		}
		s += (*this)[n - 1].x * (*this)[0].y - (*this)[0].x * (*this)[n - 1].y;
		return (s>0?s:-s) / 2;
	}

	bool is_trapezoid()
	{
		if (this->getlen() != 4)return 0;
		//vector <point> coords=this->get_coords();
		if (is_parallel((*this)[0], (*this)[1], (*this)[2], (*this)[3]) ||
			is_parallel((*this)[1], (*this)[2], (*this)[3], (*this)[0]))
			return 1;
	}

};

class triangle :public polygon
{
public:
	void push_back(point a)
	{
		if (this->getlen() < 3) this->polygon::push_back(a);
		else cout << "triangle is three points figure only\n";
	}
};

class trapezoid :public polygon
{
public:
	trapezoid()
	{

		float x, y;

		for (int i = 0; i < 4; i++)
		{
			cout << "trapezoid's coords x,y:\n";
			cin >> x >> y;
			this->push_back(x, y);

		}
		if (!this->is_trapezoid())
		{
			this->clear_coords();
			cout << "not trapezoid, points cleared";
		}
	}

	trapezoid(vector <point> v)
	{
		for (auto i : v)
		{
			this->push_back(i);
		}
		if (!this->is_trapezoid())
		{
			this->clear_coords();
			cout << "not trapezoid, points cleared";
		}
	}


};

class regular_polygon :public polygon
{
public:
	//manually init reg. polygon with central coords and radius of circumscribed circle
	regular_polygon()
	{
		int n;
		float r, x, y;
		cout << "center coords:\nx,y\n";
		cin >> x >> y;
		cout << "n,r\n";
		cin >> n >> r;
		for (int i = 0; i < n; i++)
		{
			push_back(x + r * cos(2 * PI * i / n), y + r * sin(2 * PI * i / n));
		}
	}

	regular_polygon(int n, float r, float x, float y)
	{
		for (int i = 0; i < n; i++)
		{
			push_back(x + r * cos(2 * PI * i / n), y + r * sin(2 * PI * i / n));
		}
	}
};


