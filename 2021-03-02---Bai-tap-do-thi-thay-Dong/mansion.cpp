#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

#define maxN 200005

int n, m, k;
vector<pii> rooms;
vector<pii> adj[maxN][2];

vector<pii> row[maxN], col[maxN];

int cntState;
pii state[maxN * 2];
int id[maxN][2];
int d[maxN * 2];

void initGraph() {
	for (int i = 0; i < (int)rooms.size(); i++) {
		int x = rooms[i].fi, y = rooms[i].se;
		row[x].push_back(pii(y, i));
		col[y].push_back(pii(x, i));
	}

	for (int x = 1; x <= m; x++) {
		sort(row[x].begin(), row[x].end());
		for (int i = 0; i < (int)row[x].size() - 1; i++) {
			int u = row[x][i].se, v = row[x][i+1].se;
			int w = row[x][i+1].fi - row[x][i].fi;

			adj[u][0].push_back(pii(v, w));
			adj[v][0].push_back(pii(u, w));
		}
	}

	for (int y = 1; y <= n; y++) {
		sort(col[y].begin(), col[y].end());
		for (int i = 0; i < (int)col[y].size() - 1; i++) {
			int u = col[y][i].se, v = col[y][i+1].se;
			int w = col[y][i+1].fi - col[y][i].fi;

			adj[u][1].push_back(pii(v, w));
			adj[v][1].push_back(pii(u, w));
		}
	}
}

void printGraph() {
	for (int i = 0; i < k + 2; i++) {
		cout << i << '\n';
		for (pii e : adj[i][1]) {
			cout << e.fi << ' ' << e.se << '\n';
		}
	}
}

void initState() {
	cntState = 0;
	for (int i = 0; i < k + 2; i++) for (int j = 0; j < 2; j++) {
		state[cntState] = pii(i, j);
		id[i][j] = cntState;
		cntState++;
	}
}

void dijkstra(int u0, int mask) {
	memset(d, -1, sizeof d);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[id[u0][mask]] = 0;
	pq.push(pii(d[id[u0][mask]], id[u0][mask]));

	while (!pq.empty()) {
		int cur = pq.top().se, wCur = pq.top().fi; pq.pop();
		if (wCur != d[cur]) continue;
		int u = state[cur].fi, mask = state[cur].se;


		for (pii e : adj[u][mask]) {
			int v = e.fi, w = e.se, newState = id[v][mask];
			if (d[newState] == -1 || d[newState] > d[cur] + w) {
				d[newState] = d[cur] + w;
				pq.push(pii(d[newState], newState));
			}
		}
		for (pii e : adj[u][mask ^ 1]) {
			int v = e.fi, w = e.se + 1, newState = id[v][mask ^ 1];
			if (d[newState] == -1 || d[newState] > d[cur] + w) {
				d[newState] = d[cur] + w;
				pq.push(pii(d[newState], newState));
			}
		}
	}
} 

int main() {
	freopen("input.txt", "r", stdin);

	cin >> m >> n >> k;
	rooms.push_back(pii(1, 1));
	rooms.push_back(pii(m, n));
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		rooms.push_back(pii(x, y));
	}

	initGraph();
	initState();
	dijkstra(0, 0);

	int res = 1e9; {
		if (d[id[1][0]] != -1 && d[id[1][0]] < res)
			res = d[id[1][0]];
		if (d[id[1][1]] != -1 && d[id[1][1]] < res)
			res = d[id[1][1]];
		if (res == 1e9) res = -1;
	}
	cout << res;

	return 0;
}