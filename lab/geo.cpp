#include <bits/stdc++.h>
using namespace std;
namespace sol {

#define Vector Point

template<class T>
struct Point {
	static constexpr T eps = 1e-9;

	T x, y;
	Point() {}
	Point(T _x, T _y) {x = _x; y = _y;}

	bool operator<(Point p) const {
		if (abs(x-p.x) > eps) return x < p.x;
		return y < p.y;
	}

	bool operator==(Point p) const {
		return (abs(x-p.x) < eps) && (abs(y-p.y) < eps);
	}

	T operator&(Vector v) {return x*v.y - y*v.x;}
	T operator*(Vector v) {return x*v.x + y*v.y;}
	Vector operator*(T d) {return Vector(x*d, y*d);}
	Vector operator/(T d) {return Vector(x/d, y/d);}
	Vector operator+(Vector v) {return Vector(x+v.x, y+v.y);}
	Vector operator-(Vector v) {return Vector(x-v.x, y-v.y);}
	void operator*=(T d) {x *= d; y *= d;}
	void operator/=(T d) {x /= d; y /= d;}
	void operator+=(Vector v) {x += v.x; y += v.y;}
	void operator-=(Vector v) {x -= v.x; y -= v.y;}

	T len2() {return x*x + y*y;}
	long double len() {return sqrt(len2());}
	T dist2(Point p) {return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);}
	long double dist(Point p) {return sqrt(dist2(p));}

	Point rotated(long double a)
	{return Point(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a));}
	void rotate(long double a) {
		T cx = x*cos(a) - y*sin(a);
		T cy = x*sin(a) + y*cos(a);
		x = cx; y = cy;
	}
};

template<class P>
int relative_pos(P q, P p1, P p2, long double eps) {
	long double cross = (q-p1)&(p2-p1);
	if (cross > eps) return 1;
	if (cross < -eps) return -1;
	return 0;
}

template<class P>
long double line_dist(P q, P p1, P p2) {
	return abs(((q-p1)&(p2-p1))/(p2-p1).len());
}
template<class P>
bool has_projection(P q, P p1, P p2, P& res) {
	if (p1 == p2) return false;
	long double s = ((q-p1)*(p2-p1))/(p1-p2).len2();
	res = (p1 + ((p2-p1)*s));
	return true;
}

void test() {
	Point<long double> p1, p2, p3, p4;

	for (int i = 0; i < 100000; i += 1) {
		p1 = {rand()%100, rand()%100};
		p2 = {rand()%100, rand()%100};
		p3 = {rand()%100, rand()%100};
		if (!has_projection(p1, p2, p3, p4)) continue;
		if (abs(p1.dist(p4) - line_dist(p1, p2, p3)) > Point<long double>::eps) {
			cout << "WA";
			return;
		}
	}

	cout << "AC";
}

}

int main() {
	srand(time(0));
	sol::test();
}
