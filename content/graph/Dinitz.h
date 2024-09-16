/**
 * Author: me
 * Date: 2024-09-16
 * License: CC0
 * Source: https://https://github.com/dothething1DA/cp_template/edit/main/content/graph/Dinitz.h
 * Description: Flow algorithm with complexity $O(V^{2}E)$.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */

#pragma once

struct Edge {
	int u, v;
	long long capacity;
	long long flow = 0;

	Edge() {}
	Edge(int a, int b, long long c) {
		u = a;
		v = b;
		capacity = c;
	}

	bool passable() {return capacity > flow;}
	long long remaining() {return capacity - flow;}
};

struct Network {
	// Remember to check limits
	static constexpr int N_MAX = 101;
	static constexpr long long INF = 1e14;

	int n;
	int s, t;

	// bfs distance from source
	// used to determine if an edge is in layer graph
	int dist[N_MAX];

	// Next edge to send flow while DFS-ing
	// If we can't send flow through this edge, it won't be used until next layer
	// In that case, increase next[u] by 1(progress to next edge)
	int next[N_MAX];

	vector<Edge> edges;
	vector<int> edgesFrom[N_MAX];

	// Initialisation functions
	Network() {}
	void init(int _n, int _s, int _t) {
		n = _n;
		s = _s;
		t = _t;
	}

	void addEdge(int u, int v, long long w) {
		edges.push_back(Edge(u, v, w));
		edgesFrom[u].push_back(edges.size()-1);
		edges.push_back(Edge(v, u, 0));
		edgesFrom[v].push_back(edges.size()-1);
	}
	// End initialisation functions

	// BFS to create layer graph
	queue<int> bfs;
	bool pathExist() {
		while (bfs.size()) bfs.pop();
		for (int i = 0; i <= n; i += 1) if (i != s) dist[i] = -1;

		bfs.push(s);
		while (bfs.size()) {
			int u = bfs.front(); bfs.pop();
			if (u == t) break;
			for (int id: edgesFrom[u]) if (edges[id].passable()) {
				int v = edges[id].v;
				if (dist[v] != -1) continue;
				dist[v] = dist[u] + 1;
				bfs.push(v);
			}
		}

		return dist[t] != -1;
	}

	// DFS try to send a flow through each edges of a vertice
	long long flowSent(int u, long long f=INF) {
		if (u == t) return f;
		if (f == 0) return 0;

		for (int& i = next[u]; i < edgesFrom[u].size(); i += 1) {
			int id = edgesFrom[u][i];
			if (dist[edges[id].v] != dist[u] + 1) continue;
			long long attempt = flowSent(edges[id].v, min(f, edges[id].remaining()));
			if (attempt) {
				edges[id].flow += attempt;
				edges[id^1].flow -= attempt;
				return attempt;
			}
		}

		return 0;
	}

	// Dinitz algorithm
	long long maxFlow() {
		long long res = 0;
		while (pathExist()) {
			for (int i = 0; i <= n; i += 1) next[i] = 0;
			while (true) {
				long long f = flowSent(s);
				if (f == 0) break;
				res += f;
			}
		}
		return res;
	}
};

Network graph;

int main() {
	graph.init(6, 0, 5);
	int m = 9;
	for (int i = 0; i < m; i += 1) {
		int u, v, c;
		cin >> u >> v >> c;
		graph.addEdge(u, v, c);
	}

	cout << graph.maxFlow();
}

