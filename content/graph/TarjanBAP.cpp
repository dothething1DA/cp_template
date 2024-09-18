/**
 * Author: me
 * Date: 2024-09-16
 * License: CC0
 * Source: https://https://github.com/dothething1DA/cp_template/edit/main/content/graph/Tarjan_BAP.h
 * Description: Bridges and Articulation point with graph traversal.
 * Time: $O(V + E)$
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */

// Remember to check limits
struct Graph {
	static constexpr int N_MAX = 1e5; //(*)

	int earliest[N_MAX];
	int visitTime[N_MAX];
	vector<int> nv[N_MAX];
	bitset<N_MAX> isArticulationPoint;
	int n, bridgeCnt, dfsRoot, rootChildren, curTime;

	Graph() {}
	void init(int _n) {
		n = _n;
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

int main() {
	int n, m; cin >> n >> m;
	g.init(n);
	for (int i = 0; i < m; i += 1) {
		int u, v; cin >> u >> v;
		g.addEdge(u, v);
	}

	// When graph is not connected
	for (int i = 1; i <= n; i += 1) if (!g.visitTime[i]) g.startFrom(i);

	int ap = 0;
	for (int i = 1; i <= n; i += 1) ap += g.isArticulationPoint[i];
	cout << ap << " " << g.bridgeCnt;
}
*/