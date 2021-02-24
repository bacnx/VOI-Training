// http://csloj.ddns.net/problem/598
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

#define INF 1e9
const int N = 1e4 + 4;

struct Edge {
	int u, v, w;
	Edge(const int &_u = 0, const int &_v = 0, const int &_w = 0) {
		u = _u, v = _v, w = _w;
	}
};

int n, m, k, s, t;
vector<pii> adj[N], reverseAdj[N];
vector<Edge> edges;

int ds[N], dt[N];


void init() {
	for (int i = 1; i <= n; i++) {
		ds[i] = dt[i] = INF;
	}
}

void dijkstra(int u0, vector<pii> adj[], int d[]) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[u0] = 0;
	pq.push(pii(0, u0));

	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		int u = cur.se;
		if (cur.fi != d[u]) continue;

		for (pii e : adj[u]) {
			int v = e.fi, w = e.se;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push(pii(d[v], v));
			}
		}
	}
}

int main() {
	cin >> n >> m >> k >> s >> t;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back(pii(v, w));
		reverseAdj[v].push_back(pii(u, w));
	}
	for (int i = 0; i < k; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges.push_back(Edge(u, v, w));
	}

	init();
	dijkstra(s, adj, ds);
	dijkstra(t, reverseAdj, dt);

	int res = INF;
	for (Edge e : edges) {
		int tmp = e.w + min(ds[e.u] + dt[e.v], ds[e.v] + dt[e.u]);
		res = min(res, tmp);
	}
	if (res == INF) res = -1;

	cout << res;

	return 0;
}