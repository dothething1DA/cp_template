/**
 * Author: me
 * Description: SCC with Tarjan algo.
 * Time: $O(V + E)$
 */

struct Graph {
	stack<int> st;
	vector<int> vt;
	vector<int> et;
	vector<int> scc;
	int dfsTime = 1;
	int scc_count, n;
	vector<bool> finished;
	vector<vector<int>> nv;

	void init(int _n) {
		n = _n;
		vt.resize(n+1);
		et.resize(n+1);
		nv.resize(n+1);
		scc.resize(n+1);
		finished.resize(n+1);
	}

	void addEdge(int u, int v) {
		nv[u].push_back(v);
	}

	void traverse(int u) {
		if (vt[u]) return;

		st.push(u);
		vt[u] = dfsTime;
		et[u] = dfsTime++;

		for (int v: nv[u]) if (!finished[v]) {
			if (vt[v] == 0) {
				traverse(v);
				et[u] = min(et[v], et[u]);
			}
			else et[u] = min(et[u], vt[v]);
		}

		if (vt[u] == et[u]) {
			int cur;
			do {
				cur = st.top();
				finished[cur] = 1;
				scc[cur] = scc_count;
				st.pop();
			} while (cur != u);

			scc_count += 1;
		}
	}

	void findAllScc() {
		for (int i = 1; i <= n; i += 1) traverse(i);
	}
};


/*Graph g;

void example(int n, int m) {
	g.init(n);
	for (int i = 0; i < m; i += 1) {
		int u, v; cin >> u >> v;
		if (u != v) g.addEdge(u, v);
	}

	g.findAllScc();
	cout << g.scc_count;
}*/
