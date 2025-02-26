/**
 * Author: me
 * Description: Find pattern in a string.
 * Time: $O(N)$
 */

struct Prefix_function {
	int len;
	// pf[i] = longest proper prefix that
	// also is a suffix of substring s[0..i]
	vector<int> pf;

	void init(string s) {
		len = s.length();
		pf.resize(len); pf[0] = 0;
		for (int i = 1; i < len; i += 1) {
			int j = pf[i-1];
			while (j && s[i] != s[j]) j = pf[j-1];
			if (s[i] == s[j]) j += 1; pf[i] = j;
		}
	}
};

/*Prefix_function pf;

bool kmp(string s, string pattern) {
	string temp = pattern;
	temp += '#'; temp += s;
	pf.init(temp);

	// index i with pf.pf[i] = x is the ending
	// of an occurrence of pattern in s
	for (int x: pf.pf)
	if (x == pattern.length()) return true;

	return false;
}*/
