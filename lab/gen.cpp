#include <bits/stdc++.h>
using namespace std;

int main() {
	int x; cin >> x;
	freopen("input.txt", "w", stdout);
	for (int i = 0; i < x; i += 1) cout << char('a' + (rand()%26));
}
