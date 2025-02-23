/**
 * Author: me
 * Description: SCC finding with kosaraju algo.
 * Time: $O(V + E)$
 */

struct Graph {
	vector<int> scc;
	int n, scc_count;
	int finishTime = 1;
	vector<int> finishAt;
	vector<bool> visited;
	vector<vector<int>> graph;
	vector<vector<int>> revGraph;

	void init(int _n) {
		n = _n;
		scc.resize(n+1);
		graph.resize(n+1);
		visited.resize(n+1);
		revGraph.resize(n+1);
		finishAt.resize(n+1);
	}

	void addEdge(int u, int v) {
		graph[u].push_back(v);
		revGraph[v].push_back(u);
	}

	void markFinishTime(int u) {
		if (visited[u]) return;
		visited[u] = 1;
		for (int v: graph[u]) markFinishTime(v);
		finishAt[finishTime++] = u;
	}

	void markScc(int u) {
		if (visited[u]) return;
		visited[u] = 1;
		scc[u] = scc_count;
		for (int v: revGraph[u]) markScc(v);
	}

	void findAllScc() {
		for (int i = 1; i <= n; i += 1) markFinishTime(i);
		for (int i = 1; i <= n; i += 1) visited[i] = false;

		for (int i = n; i; i -= 1) if (!visited[finishAt[i]]) {
			markScc(finishAt[i]);
			scc_count += 1;
		}
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
