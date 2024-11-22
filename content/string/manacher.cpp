/**
 * Author: me
 * Description: Find longest palindrome centered at each index.
 * Initialise with original 0-indexed string. QUERYING IS 1-INDEXED.
 * Time: $O(N)$
 */

struct Manacher {
	string s;
	vector<int> pl;

	void calc() {
		int n = s.length() - 1;
		int l = 0, r = 0;

		for (int i = 1; i <= n; i += 1) {
			if (i < r) pl[i] = min(r-i, pl[l+r-i]);
			while (s[i-pl[i]-1] == s[i+pl[i]+1]) pl[i] += 1;
			if (i + pl[i] > r) {
				l = i - pl[i];
				r = i + pl[i];
			}
		}
	}

	Manacher() {}
	void init(string _s, char f='~') {
		s = "@"; s += f;
		for (char c: _s)
		{s += c; s += f;} s += '|';
		pl.resize(s.length(), 0);
		calc();
	}

	// Query for substring [l, r]
	// on original string with 1-indexed
	bool is_palindrome(int l, int r) {
		l <<= 1; r <<= 1;
		int mid = (l+r) >> 1;
		return mid + pl[mid] >= r;
	}
};
/*
Manacher mana;

void example() {
	string s;
	cin >> s;
	mana.init(s);
	int l, r; cin >> l >> r;
	cout << mana.is_palindrome(l, r);
}*/
