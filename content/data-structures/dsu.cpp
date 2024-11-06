/**
 * Author: me
 * Description: Disjoint-set data structure.
 * Suitable for both 0-indexed and 1-indexed.
 * Time: $O(\alpha(N))$
 */

struct DSU {
	int n, t;
	vector<int> par;

	DSU() {}
	void init(int _n) {
		n = _n + 1;
		par.resize(n, -1);
	}

	int root(int v) {
		if (par[v] < 0) return v;
		int res = root(par[v]);
		par[v] = res;
		return res;
	}

	void join(int u, int v) {
		u = root(u); v = root(v);
		if (u == v) return;
		if (par[u] > par[v]) {u ^= v; v ^= u; u ^= v;}
		par[u] += par[v]; par[v] = u;
	}

	bool same_set(int u, int v) {return root(u) == root(v);}
};

DSU dsu;

void example(int n, int q) {
	dsu.init(n);
	int t, u, v;
	while (q--) {
		cin >> t >> u >> v;
		if (t) cout << dsu.same_set(u, v) << "\n";
		else dsu.join(u, v);
	}
}
