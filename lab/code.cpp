#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
	string s;
	vector<int> p;
	int mnc, mxc, len;
	vector<queue<int>> f;
	vector<vector<int>> c;

	bool diff(int i1, int i2, int plen, int id) {
		if (c[id][i1] != c[id][i2]) return true;
		i1 = (i1+plen)%len; i2 = (i2+plen)%len;
		return (c[id][i1] != c[id][i2]);
	}

	void update_label(int plen) {
		c.push_back({});
		int id = c.size()-1;
		c[id].resize(len); c[id][p[0]] = 0;
		for (int i = 1; i < len; i += 1) {
			int ci = p[i];
			int pi = p[i-1];
			c[id][ci] = c[id][pi];
			if (diff(ci, pi, plen, id-1))
			c[id][ci] += 1; mxc = c[id][ci];
		}
	}

	void sort_css(int& slen) {
		for (int& x: p) {
			x = ((x-slen)%len+len)%len;
			f[c[c.size()-1][x]].push(x);
		}

		int pid = 0;
		for (int i = 0; i <= mxc; i += 1)
		while (f[i].size()) {
			p[pid++] = f[i].front();
			f[i].pop();
		}

		update_label(slen); slen <<= 1;
	}

	void init(string _s) {
		s = _s; len = s.length();
		f.resize(max(128, len));
		mnc = INT_MAX; mxc = -INT_MAX;
		for (int i = 0; i < len; i += 1) {
			mnc = min(mnc, int(s[i]));
			mxc = max(mxc, int(s[i]));
			f[int(s[i])].push(i);
		}

		c.push_back({});
		c[0].resize(len);
		for (int i = mnc; i <= mxc; i += 1)
		while (f[i].size()) {
			p.push_back(f[i].front());
			c[0][f[i].front()] = i-mnc;
			f[i].pop();
		}

		int slen = 1;
		while (slen < len) sort_css(slen);
	}
};

SuffixArray sa;

int main() {
	/*ios_base::sync_with_stdio(false);
	cin.tie(0);*/

	string s;
	cin >> s;
	sa.init(s+"!");

	for (int i = 1; i < sa.p.size(); i += 1)
	cout << sa.p[i] << " ";
}
