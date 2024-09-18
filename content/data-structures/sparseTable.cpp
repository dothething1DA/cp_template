/**
 * Author: me
 * Description: Sparse table for RMQ.
 * Time: $O(N \log N + Q)$
 */

struct SparseTable {
	// CAREFUL
	static constexpr int N_MAX = 5e5 + 1;
	static constexpr int L_MAX = 20; // 2^19 > N_MAX

	// Length of the array
	int len;

	// st[i][j] = minimum value in the segment length 2^i starting at j
	int st[L_MAX][N_MAX];

	SparseTable() {}
	void init(int _len, int (&a)[]) {
		len = _len;
		for (int i = 0; i < len; i += 1) st[0][i] = a[i];
		for (int i = 1; i < L_MAX; i += 1)
		// CAREFUL(MIN-MAX)
		for (int j = 0; j < len; j += 1) st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
	}

	// min value in [l, r]
	int retrieve(int l, int r) {
		int i = __lg(r-l+1);
		// CAREFUL(MIN-MAX)
		return min(st[i][l], st[i][r - (1 << i) + 1]);
	}
};
/*
SparseTable rmq;

int main() {
	int n, q; cin >> n >> q;
	int arr[n]; for (int i = 0; i < n; i += 1) cin >> arr[i];

	rmq.init(n, arr);

	int l, r;
	for (int i = 0; i < q; i += 1) {
		cin >> l >> r;
		cout << rmq.retrieve(l, r-1) << "\n";
	}
}
*/