#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 4003;
const int MOD = 1e9 + 7;

int n, m;
int g[MAX][MAX];
vector<int> adj[MAX];

bool fre[MAX];
int res[MAX];

void bfs(int u0) {
    memset(fre, true, sizeof fre);
    queue<pii> q;
    q.push(pii(u0, 1));

    while (!q.empty()) {
        int u = q.front().first, d = q.front().second; q.pop();
        res[d]++; if (res[d] >= MOD) res[d] -= MOD;
        fre[u] = false;
        if (d == n) continue;

        for (int v : adj[u]) {
            if (fre[v]) {
                g[u][v] = 1; g[v][u] = 0;
                if (d < n) q.push(pii(v, d+1));
            } else if (g[u][v])
                if (d < n) q.push(pii(v, d+1));
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("lottery.inp", "r", stdin);
    freopen("lottery.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u][v] = 1; g[v][u] = 0;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) bfs(i);
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';

    return 0;
}