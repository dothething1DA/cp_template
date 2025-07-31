/**
 * Author: me
 * Description: Triangle. NOT TESTED!
 * Time:N/A
 */

template<class T>
struct Triangle {
	static constexpr T eps = 1e-9;

	Point<T> a, b, c;

	bool init_succeed(Point<T> _a, Point<T> _b, Point<T> _c) {
		a = _a; b = _b; c = _c;
		if (collinear(a, b, c)) return false;
		T ab = a.dist(b); T bc = b.dist(c); T ca = c.dist(a);
		return (ab+bc > ca) && (bc+ca > ab) && (ca+ab > bc);
	}

	T perimeter() {return (a.dist(b)+b.dist(c)+c.dist(a));}

	T area() {
		T s = perimeter()*0.5l;
		T ab = a.dist(b); T bc = b.dist(c); T ca = c.dist(a);
		return sqrt(s*(s-ab)*(s-bc)*(s-ca));
	}
};
