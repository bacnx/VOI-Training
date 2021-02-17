// http://csloj.ddns.net/problem/591
#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define fi first
#define se second

#define INF 1e18
#define N 5003

int n, m, k;
int u0, v0;
int value[N];
vector<pli> adj[N];

ll dp[2][N];

void dijkstra(int t) {
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	vector<bool> fre(n + 1, true);
	int be = (t == 0 ? u0 : v0);
	dp[t][be] = 0;
	pq.push(pli(0, be));

	while (!pq.empty()) {
		pli cur = pq.top(); pq.pop();
		int u = cur.se;
		if (!fre[u] || cur.fi != dp[t][u]) continue;
		fre[u] = false;

		for (pii e : adj[u]) {
			int v = e.fi, w = e.se;
			if (!fre[v]) continue;

			if (dp[t][v] == 0 || dp[t][v] > dp[t][u] + w) {
				dp[t][v] = dp[t][u] + w;
				pq.push(pli(dp[t][v], v));
			}
		}
	}
}

int main() {
    cin >> n >> m >> k;
    cin >> u0 >> v0;
    for (int i = 0; i < k; i++) {
        int u, p; cin >> u >> p;
        value[u] = p;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }

    dijkstra(0);
    dijkstra(1);

    ll res = INF; int resId;
    for (int i = 1; i <= n; i++) if (value[i]) {
    	ll tmp = value[i] + dp[0][i] + dp[1][i];
    	if (res > tmp) {
    		res = tmp;
    		resId = i;
    	}
    }
    cout << res << ' ' << resId;

	return 0;
}