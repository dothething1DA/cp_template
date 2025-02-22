/**
 * Author: me
 * Description: Bridges and Articulation point with graph traversal.
 * Time: $O(V + E)$
 */

struct Graph {
	vector<int> earliest;
	vector<int> visitTime;
	vector<vector<int>> nv;
	vector<bool> isArticulationPoint;
	int n, bridgeCnt, dfsRoot, rootChildren, curTime;

	Graph() {}
	void init(int _n) {
		n = _n;
		nv.resize(_n+1);
		earliest.resize(_n+1);
		visitTime.resize(_n+1);
		isArticulationPoint.resize(_n+1, 0);
	}

	void addEdge(int u, int v) {
		nv[u].push_back(v);
		nv[v].push_back(u);
	}

	void traverse(int u, int p) {
		earliest[u] = curTime;
		visitTime[u] = curTime++;

		for (int v: nv[u]) if (v != p) {
			if (visitTime[v]) earliest[u] = min(earliest[u], visitTime[v]);
			else {
				if (u == dfsRoot) rootChildren += 1;
				traverse(v, u);
				if (earliest[v] >= visitTime[u]) {
					isArticulationPoint[u] = 1;
					// (u, v) is bridge
					if (earliest[v] > visitTime[u]) bridgeCnt += 1;
				}
				earliest[u] = min(earliest[u], earliest[v]);
			}
		}
	}

	void startFrom(int root) {
		curTime = 1;
		dfsRoot = root;
		rootChildren = 0;
		traverse(root, root);
		isArticulationPoint[root] = rootChildren > 1;
	}
};
/*
Graph g;

void example(int n, int m) {
	g.init(n);
	for (int i = 0; i < m; i += 1) {
		int u, v; cin >> u >> v;
		g.addEdge(u, v);
	}

	// When graph is not connected
	for (int i = 1; i <= n; i += 1)
	if (!g.visitTime[i]) g.startFrom(i);

	int ap = 0;
	for (int i = 1; i <= n; i += 1)
	ap += g.isArticulationPoint[i];
	cout << ap << " " << g.bridgeCnt;
}
*/
