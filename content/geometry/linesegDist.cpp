/**
 * Author: me
 * Description: Distance between q and line segment p1p2.
 * Time: $O(1)$
 */

template<class P>
long double lineseg_dist(P q, P p1, P p2) {
	if (p1 == p2) return q.dist(p1);
	long double s = ((q-p1)*(p2-p1))/(p1-p2).len2();
	if (s < 0.0) return q.dist(p1);
	if (s > 1.0) return q.dist(p2);
	return line_dist(q, p1, p2);
}
