/**
 * Author: me
 * Description: Find perpendicular projection of q on line p1p2.
 * Time: $O(1)$
 */
 
template<class P>
bool has_projection(P q, P p1, P p2, P& res) {
	if (p1 == p2) return false;
	long double s = ((q-p1)*(p2-p1))/(p1-p2).len2();
	res = (p1 + ((p2-p1)*s));
	return true;
}