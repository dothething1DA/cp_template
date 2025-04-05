template<class T>
struct Line {
	static constexpr T eps = 1e-9;

	T a, b, c;
	Line() {}
	Line(T x, T y, T z) {a = x; b = y; c = z;}

	bool operator==(Line l) const {
		if (abs(a-l.a) > eps) return false;
		if (abs(b-l.b) > eps) return false;
		return abs(c-l.c) < eps;
	}

	// from two DISTINCT point
	void init(Point<T> p1, Point<T> p2) {
		if (abs(p1.x-p2.x) < eps) {
			a = 1; b = 0; c = -p1.x;
			return;
		}

		a = (p2.y - p1.y)/(p1.x - p2.x);
		b = 1; c = 0.0 - a*p1.x - p1.y;
	}

	// from point and slope
	void init(Point<T> p, T m) {
		a = -m; b = 1;
		c = 0.0 - (p.x*a + p.y*b);
	}

	bool parallel_with(Line l)
	{return abs(a-l.a) < eps && abs(b-l.b) < eps;}

	// Careful for parallel or ==
	Point<T> intersect(Line l) {
		T x = (b*l.c - c*l.b)/(a*l.b - b*l.a);
		T y = (c*l.a - a*l.c)/(a*l.b - b*l.a);
		return {x, y};
	}
};
