/**
 * Author: me
 * Description: Distance between q and line p1p2. Careful when p1=p2
 * Time: $O(1)$
 */

// CAREFUL: p1 == p2
template<class P>
long double line_dist(P q, P p1, P p2) {
	return abs(((q-p1)&(p2-p1))/(p2-p1).len());
}
