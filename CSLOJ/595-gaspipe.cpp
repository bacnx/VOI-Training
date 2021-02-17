// http://csloj.ddns.net/problem/595
#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define fi first
#define se second

const int N = 1e4 + 4;
const ll INF = 1e18;

bool minimize(ll &a, ll b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

int n, m, k;
vector<pii> adj[N];

ll d[N*24];
int cnt = 0;
int stateId[N][24];
pii state[24*N];


void initState() {
	for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) {
		cnt++;
		stateId[i][j] = cnt;
		state[cnt] = pii(i, j);
	}
}

void initD() {
	for (int i = 0; i <= cnt; i++) {
		d[i] = INF;
	}
}

void dijkstra() {
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	vector<bool> fre(cnt + 1, true);
	d[stateId[1][0]] = 0;
	pq.push(pli(0, stateId[1][0]));

	while (!pq.empty()) {
		pli sta = pq.top(); pq.pop();
		int cur = sta.se;
		if (!fre[cur] || sta.fi != d[cur]) continue;
		fre[cur] = false;
		int u = state[cur].fi, t = state[cur].se;

		for (pii e : adj[u]) {
			int v = e.fi, w = e.se;

			int next = stateId[v][t]; // không chọn đường này làm đường hầm 
			if (fre[next] && minimize(d[next], d[cur] + w)) {
				pq.push(pli(d[next], next));
			}

			next = stateId[v][t+1]; // chọn đường này làm đường hầm 
			if (fre[next] && t < k && minimize(d[next], d[cur])) {
				pq.push(pli(d[next], next));
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back(pii(v, w));
		adj[v].push_back(pii(u, w));
	}

	initState();
	initD();
	dijkstra();

	cout << d[stateId[n][k]];

	return 0;
}