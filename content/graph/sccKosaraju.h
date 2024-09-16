/**
 * Author: me
 * Date: 2024-09-16
 * License: CC0
 * Source: https://https://github.com/dothething1DA/cp_template/edit/main/content/graph/sccKosaraju.h
 * Description: SCC finding with kosaraju algo.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */

struct Graph {
	static constexpr int N_MAX = 1e4 + 1; //(*)

	int scc[N_MAX];
	int n, scc_count;
	int finishTime = 1;
	int finishAt[N_MAX];
	bitset<N_MAX> visited;
	vector<int> graph[N_MAX];
	vector<int> revGraph[N_MAX];

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
		// 1-indexed vertices
		for (int i = 1; i <= n; i += 1) markFinishTime(i);
		visited = 0;
		for (int i = n; i; i -= 1) if (!visited[finishAt[i]]) {
			markScc(finishAt[i]);
			scc_count += 1;
		}
	}
};

Graph g;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> g.n >> m;
	for (int i = 0; i < m; i += 1) {
		int u, v; cin >> u >> v;
		if (u != v) g.addEdge(u, v);
	}

	g.findAllScc();
	cout << g.scc_count;
}
