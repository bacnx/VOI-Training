#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

const int maxN = 2e5 + 5;

int n, m, k;
vector<pii> rooms;
vector<pii> adj[maxN][2];


void initGraph() {
	vector<pii> row[maxN], col[maxN];
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
		for (pii e : adj[i][0]) {
			cout << e.fi << ' ' << e.se << '\n';
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	cin >> n >> m >> k;
	rooms.push_back(pii(1, 1));
	rooms.push_back(pii(m, n));
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		rooms.push_back(pii(x, y));
	}

	initGraph();

	printGraph();

	return 0;
}