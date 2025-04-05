#include <bits/stdc++.h>
using namespace std;

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
long double line_dist(P q, P p1, P p2) {
	return abs(((q-p1)&(p2-p1))/(p2-p1).len());
}

template<class P>
long double lineseg_dist(P q, P p1, P p2) {
	long double s = ((q-p1)*(p2-p1))/(p1-p2).len2();
	if (s < 0.0) return q.dist(p1);
	if (s > 1.0) return q.dist(p2);
	return line_dist(q, p1, p2);
}

int main() {
	Point<long double> p1, p2, p3;

	p1 = {0, 0};
	p2 = {1, 1};
	p3 = {0.5, 0.5};

	cout << lineseg_dist(p3, p1, p2);
}
