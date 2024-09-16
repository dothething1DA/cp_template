/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure.
 * Time: $O(\alpha(N))$
 */
#pragma once

// Remember to check limit
struct DSU {
	static constexpr int N_MAX = 2e5 + 1; //(*)

	int n, t;
	int par[N_MAX];
	int temp[N_MAX];

	DSU() {}
	void init(int _n) {
		n = _n;
		for (int i = 0; i <= n; i += 1) par[i] = -1;
	}

	int findRoot(int vt) {
		t = 0;
		while (par[vt] >= 0) {
			temp[t++] = vt;
			vt = par[vt];
		}
		for (int i = 0; i < t; i += 1) par[temp[i]] = vt;
		return vt;
	}

	void join(int u, int v) {
		u = findRoot(u);
		v = findRoot(v);
		if (u == v) return;
		if (par[u] > par[v]) {u^=v;v^=u;u^=v;}
		par[u] += par[v];
		par[v] = u;
	}

	bool sameSet(int u, int v) {
		return findRoot(u) == findRoot(v);
	}
};

DSU dsu;

int main() {
	int n, q; cin >> n >> q;
	dsu.init(n);

	int t, u, v;
	for (int i = 0; i < q; i += 1) {
		cin >> t >> u >> v;
		if (!t) dsu.join(u, v);
		else cout << dsu.sameSet(u, v) << "\n";
	}
}
