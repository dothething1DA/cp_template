/**
 * Author: me
 * Description: Sparse table for static RMQ.
 * This version is 1-indexed
 * Time: $O(N \log N + Q)$
 */

struct SparseTable {
	int n;
	// st[i][j] = min/max in segment len 2^i start at j
	vector<vector<int>> st;
	
	SparseTable() {}
	void init(int _n, int* a) {
		n = _n;
		int lg2 = __lg(n) + 2;
		st.resize(lg2, vector<int>(n+1));
		for (int i = 1; i <= n; i += 1) st[0][i] = a[i];
		
		for (int i = 1; i < lg2; i += 1)
		for (int j = 1; j <= n; j += 1)
		// CAREFUL MIN-MAX
		st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
	}
	
	// Query for [l, r]
	int retrieve(int l, int r) {
		int i = __lg(r-l+1);
		//CAREFUL MIN-MAX
		return min(st[i][l], st[i][r - (1 << i) + 1]);
	}
};

/*
SparseTable rmq;

void example(int n, int q) {
	int a[n+1];
	for (int i = 1; i <= n; i += 1) cin >> a[i];
	rmq.init(n, a);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << rmq.retrieve(l, r) << "\n";
	}
}
*/
