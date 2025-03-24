/**
 * Author: me
 * Description: Point and Vector.
 * Time: N/A
 */

#define Vector Point /** keep-include */

template<class T>
struct Point {
	// CAREFUL
	static constexpr T eps = 1e-9;

	T x, y;
	Point() {}
	Point(T _x, T _y) {x = _x; y = _y;}

	// Comparison
	bool operator<(Point p) const {
		if (abs(x - p.x) > eps) return x < p.x;
		return y < p.y;
	}

	bool operator==(Point p) const {
		return (abs(x-p.x) < eps) && (abs(y-p.y) < eps);
	}

	// Calculation
	T operator&(Vector v) {return x*v.y - y*v.x;}
	T operator*(Vector v) {return x*v.x + y*v.y;}
	Vector operator*(T d) {return Vector(x*d, y*d);}
	Vector operator/(T d) {return Vector(x/d, y/d);}
	Vector operator+(Vector v) {return Vector(x+v.x,y+v.y);}
	Vector operator-(Vector v) {return Vector(x-v.x,y-v.y);}

	void operator*=(T d) {x *= d; y *= d;}
	void operator/=(T d) {x /= d; y /= d;}
	void operator+=(Vector v) {x += v.x; y += v.y;}
	void operator-=(Vector v) {x -= v.x; y -= v.y;}

	T len2() {return x*x + y*y;}
	long double len() {return sqrt(len2());}
	T dist2(Point p) {return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);}
	long double dist(Point p) {return sqrt(dist2(p));}

	// Rotate counter clockwise around (0, 0)
	Point rotated(long double a)
	{return Point(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));}
	void rotate(long double a) {
		T cx = x*cos(a) - y*sin(a);
		T cy = x*sin(a) + y*cos(a);
		x = cx; y = cy;
	}
};
