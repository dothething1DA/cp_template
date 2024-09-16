#include <bits/stdc++.h>
using namespace std;

struct Graph {
	static constexpr int N_MAX = 1e4 + 1; // (*)

	int vt[N_MAX];
	int et[N_MAX];
	stack<int> st;
	int scc[N_MAX];
	int dfsTime = 1;
	int scc_count, n;
	bitset<N_MAX> finished;
	vector<int> graph[N_MAX];

	void addEdge(int u, int v) {
		graph[u].push_back(v);
	}

	void traverse(int u) {
		if (vt[u]) return;

		st.push(u);
		vt[u] = dfsTime;
		et[u] = dfsTime++;

		for (int v: graph[u]) if (!finished[v]) {
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
		// 1-indexed vertices
		for (int i = 1; i <= n; i += 1) traverse(i);
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
