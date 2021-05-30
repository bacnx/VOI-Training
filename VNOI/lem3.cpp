#include <bits/stdc++.h>
using namespace std;

#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define INF 1e6

int n, a[16][16];
int dp[MASK(16)][16];

void solve() {
	int nMask = MASK(n);
	for (int mask = 0; mask < nMask; mask++) for (int u = 0; u < n; u++) {
		dp[mask][u] = INF;
	}
	for (int i = 0; i < n; i++) {
		dp[MASK(i)][i] = 0;
	}

	for (int mask = 0; mask < nMask; mask++) for (int u = 0; u < n; u++) if (dp[mask][u] < INF) {
		for (int v = 0; v < n; v++) if (!BIT(mask, v)) {
			int newMask = mask | MASK(v);
			dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + a[u][v]);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> a[i][j];
	}

	solve();

	int res = INF;
	for (int i = 0; i < n; i++) {
		res = min(res, dp[MASK(n)-1][i]);
	}
	cout << res;

	return 0;
}