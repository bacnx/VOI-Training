#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

#define INF 1e9
const int maxN = 100005;

int n, m, k;
vector<int> proRooms;
vector<int> adj[maxN];
int d[maxN];

void bfs() {
    for (int i = 1; i <= n; i++) d[i] = INF;
    queue<int> q;
    for (int u : proRooms) {
        d[u] = 0;
        q.push(u);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        // cout << u << ":\n";
        for (int v : adj[u]) if (d[v] > d[u] + 1) {
            // cout << v << '\n';
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void test() {
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int v : adj[i]) cout << v << ' ';
        cout << '\n';
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int u; cin >> u;
        proRooms.push_back(u);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // test();
    bfs();

    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';

    return 0;
}