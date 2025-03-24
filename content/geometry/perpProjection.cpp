/**
 * Author: me
 * Description: Find perpendicular projection of q on line p1p2.
 * Time: $O(1)$
 */
 
template<class P>
P projection(P q, P p1, P p2) {
	long double s = ((q-p1)*(p2-p1))/(p1-p2).len2();
	return (p1 + ((p2-p1)*s));
}
