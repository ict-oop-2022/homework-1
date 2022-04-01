#include <gtest/gtest.h>
#pragma once
#include "lab1/lab1_functions.h"
using namespace std;
TEST(point, creation0) {
	ASSERT_EQ(point(1, 2), point(1, 2));
}

TEST(point, creation1)
{
	point a;
	EXPECT_EQ(a, a);
}

TEST(point, creation2)
{
	point a(1, 2);
	EXPECT_EQ(a, point(1, 2));
}

TEST(point, eq1)
{
	point a(1, 2);
	point b = a;
	EXPECT_EQ(a, b);
}

TEST(point, eq2)
{
	point a(1, 2);
	point b(a);
	EXPECT_EQ(a, b);
}

TEST(point, distance1)
{
	EXPECT_EQ(distance(point(0, 0), point(0, 0)), 0);
}

TEST(point, distance2)
{
	EXPECT_EQ(distance(point(-1, 0), point(0, 0)), 1);
}

TEST(point, distance3)
{
	EXPECT_EQ(distance(point(3, 0), point(0, 4)), 5);
}

TEST(polyline, per1)
{
	polyline p;
	p.push_back(0, 0);
	p.push_back(1, 0);
	EXPECT_EQ(p.get_perimetr(), 1);
}

TEST(polyline, per2)
{
	polyline p;
	p.push_back(0, 0);
	p.push_back(1, 0);
	p.push_back(1, 1);
	EXPECT_EQ(p.get_perimetr(), 2);
}

TEST(closed_polyline, per1)
{
	closed_polyline p;
	p.push_back(0, 0);
	p.push_back(1, 0);
	p.push_back(1, 1);
	p.push_back(0, 1);
	EXPECT_EQ(p.get_perimetr(), 4);
}

TEST(closed_polyline, per2)
{
	closed_polyline p;
	p.push_back(0, 0);
	p.push_back(0, 3);
	p.push_back(4, 3);
	ASSERT_FLOAT_EQ(p.get_perimetr(), 12);
}

TEST(closed_polyline, per3)
{
	closed_polyline p;
	p.push_back(0, 0);
	p.push_back(0, 3);
	p.push_back(4, 3);
	ASSERT_FLOAT_EQ(p.get_perimetr(), 12);
}

TEST(polygon, inny_polygon_area)
{
	polygon p;
	p.push_back(6,1);
	p.push_back(3,2);
	p.push_back(6,7);
	p.push_back(2,6);
	p.push_back(0,8);
	p.push_back(-1,5);
	p.push_back(-6,-1);

	ASSERT_FLOAT_EQ(p.get_area(), 47.5);
}

TEST(polygon, polygon_area)
{
	polygon p;
	p.push_back(0,3);
	p.push_back(3,5);
	p.push_back(5,3);
	p.push_back(3,0);

	ASSERT_FLOAT_EQ(p.get_area(), 12.5);
}

TEST(trapezoid, trap_area)
{
	vector <point> v;
	v.push_back(point(0, 3));
	v.push_back(point(3, 5));
	v.push_back(point(5, 3));
	v.push_back(point(3, 0));
	trapezoid p(v);
	ASSERT_FLOAT_EQ(p.get_area(), 12.5);
}

TEST(triangle, points_num)
{
	triangle t;
	t.push_back(point(1, 1));
	t.push_back(point(2, 1));
	t.push_back(point(3, 1));
	t.push_back(point(4, 1));
	ASSERT_FLOAT_EQ(t.getlen(),3);
}

TEST(regular_polygon, regularity)
{
	regular_polygon t(8, 8, 0, 0);
	auto c = t.get_coords();
	for (int i=0;i<c.size();i++)
		ASSERT_FLOAT_EQ(distance(t[i],t[(i+1)%8]), 6.1229349);
}

//int main()
//{
//	triangle t;
//	t.push_back(point(1, 1));
//	t.push_back(point(2, 1));
//	t.push_back(point(3, 1));
//	t.push_back(point(4, 1));
//	cout << t;
//	return RUN_ALL_TESTS();
//}

