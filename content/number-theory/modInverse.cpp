/**
 * Author: me
 * Description: Only works if m is prime
 * Time: O(50)
 */

long long m_inv(long long a, long long m) {
	return a <= 1 ? a : m - (m/a)*inv(m%a) % m;
}
