/**
 * Author: me
 * Description: determine relative position of q and line p1p2.
 * Time: $O(1)$
 */
 
// return 1: q is on clockwise side of line p1p2
// return -1: q is on counter clockwise side of line p1p1
// return 0: collinear (distance from line <= eps)
template<class P>
int relative_pos(P q, P p1, P p2, long double eps) {
	long double cross = (q-p1)&(p2-p1);
	if (cross > eps) return 1;
	if (cross < -eps) return -1;
	return 0;
}
