/**
 * Author: me
 * Description: suffix array, 0-indexed.
 * Time: $O(N \log N)$
 */

struct SuffixArray {
	string s;
	vector<int> p; //suffix array
	vector<int> rank;
	vector<int> alcp; // alcp[i] = lcp(p[i], p[i+1])
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

	void init(string _s, char last_char) {
		s = _s; s += last_char;
		len = s.length(); f.resize(max(128, len));
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

		rank.resize(len); alcp.resize(len-1);
		for (int i = 0; i < len; i += 1)
		rank[p[i]] = i; int k = 0;

		for (int i = 0; i < len; i += 1) {
			if (rank[i] == len-1) {
				k = 0;
				continue;
			}

			int j = p[rank[i]+1];
			while (max(i, j)+k < len && s[i+k] == s[j+k]) k += 1;
			alcp[rank[i]] = k; if (k) k -= 1;
		}
	}

	int lcp(int i, int j) {
		int res = 0;
		for (int k = __lg(len); k >= 0; k -= 1) {
			if (c[k][i] != c[k][j]) continue;
			i += 1 << k; i %= len;
			j += 1 << k; j %= len;
			res += 1 << k;
		}
		return res;
	}

	long long distinct_substring_cnt() {
		long long res = len-1;
		res *= (res+1ll); res >>= 1;
		for (long long x: alcp) res -= x;
		return res;
	}
};
