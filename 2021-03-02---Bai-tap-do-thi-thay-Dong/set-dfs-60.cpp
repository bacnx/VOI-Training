#include <bits/stdc++.h>
using namespace std;

#define maxN 55

int k, a, b;
bool fre[maxN][maxN];

void dfs(int u, int v) {
	if (!fre[u][v]) return;
	fre[u][v] = false;

	if (v < maxN - 1) dfs(u + 1, v + 1);
	if (u % k == 0 && v % k == 0) dfs(u/k, v/k);
	for (int i = v; i < maxN; i++) {
		if (!fre[v][i]) dfs(u, i);
	}
}

void solve() {
	cin >> k >> a >> b;
	memset(fre, true, sizeof fre);
	dfs(a, b);
	int m; cin >> m;
	while (m--) {
		int p, q; cin >> p >> q;
		if (!fre[p][q]) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
	// freopen("set.inp", "r", stdin);
	// freopen("set.out", "w", stdout);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}