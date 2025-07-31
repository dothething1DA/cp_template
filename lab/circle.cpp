/**
 * Author: me
 * Description: circle. NOT TESTED!
 * Time: N/A
 */

template<class T>
struct Circle {
	static constexpr T eps = 1e-9;

	T r;
	Point<T> center;

	Circle() {}
	Circle(T x, T y, T _r) {
		r = _r;
		center = {x, y};
	}

	bool init_succeed(Point<T> p1, Point<T> p2, T _r) {
		r = _r;
		T d2 = p1.dist2(p2);
		T det = r*r/d2 - 0.25;
		if (det < eps) return false;

		T h = sqrt(det);
		// Swap p1 and p2 for the other center
		center.x = (p1.x+p2.x)*0.5 + (p1.y-p2.y)*h;
		center.y = (p1.y+p2.y)*0.5 + (p2.x-p1.x)*h;
		return true;
	}

	// -1/0/1: out, on, in
	int relative_pos(Point<T> p) {
		T d2 = center.dist2(p);
		if (d2 > r*r) return -1;
		if (d2 < r*r) return 1;
		return 0;
	}
};
