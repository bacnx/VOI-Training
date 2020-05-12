#include <bits/stdc++.h>
using namespace std;

struct edge { int u, v, t, h; };
const int maxn = 1e4+1, maxm = 2e5+1, oo = 1e7;
typedef pair<int, int> pii;
int k, n, m, s, t, d[maxn][200];
edge e[maxm];
vector<int> g[maxn];

void dijkstra(int u0, int h0) {
    for (int i = 1; i <= n; i++)
        d[i][h0] = oo;
    d[u0][h0] = 0;

    vector<bool> avail(n+1, true);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, u0));

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (!avail[u]) continue;
        avail[u] = false;

        for (int i = 0; i < (int)g[u].size(); i++) {
            int j = g[u][i];
            int v = e[j].v, t = e[j].t, h = e[j].h;
            if (!avail[v] || h > h0) continue;

            if (d[u][h0-h] + t < d[v][h0]) {
                d[v][h0] = d[u][h0-h] + t;
                pq.push(pii(d[v][h0], v));
            }
        }
    }

    if (h0 > 0) for (int i = 1; i <= n; i++) 
        d[i][h0] = min(d[i][h0], d[i][h0-1]);
}

int main()
{
    freopen("hanhtrinh.inp", "r", stdin);
    freopen("hanhtrinh.out", "w", stdout);

    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].t >> e[i].h;
        g[e[i].u].push_back(i);
        e[m+i] = e[i]; swap(e[m+i].u, e[m+i].v);
        g[e[m+i].u].push_back(m+i);
    }
    int u, v; cin >> u >> v;
    
    for (int i = 0; i < k; i++)
        dijkstra(u, i);
    
    if (d[v][k-1] == oo) cout << -1;
    else cout << d[v][k-1];

    return 0;
}