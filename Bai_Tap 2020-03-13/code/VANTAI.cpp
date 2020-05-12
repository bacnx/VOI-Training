#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;
typedef pair<int, int> pii;
int n, m, a, b, g[maxn][maxn], d[maxn], t[maxn];

void dijkstra() {
    for (int i = 1; i <= n; i++)
        d[i] = 100000000;
    d[a] = 0; t[a] = -1;
    vector<bool> avail(n+1, true);
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(pii(d[a], a));

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (!avail[u]) continue;
        avail[u] = false;

        for (int v = 1; v <= n; v++) {
            int w = g[u][v];
            if (w == 0 || !avail[v]) continue;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                t[v] = u;
                pq.push(pii(d[v], v));
            }
        }
    }
}

int main()
{
    freopen("vantai.inp", "r", stdin);
    freopen("vantai.out", "w", stdout);

    cin >> n >> m >> a >> b;
    
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }

    dijkstra();

    vector<int> vt;
    u = b;
    while (t[u] != -1) {
        vt.push_back(g[u][t[u]]);
        u = t[u];
    }

    if ((int)vt.size() == 1) { cout << -1; return 0; }
    int temp = 0, res = 100000000;
    for (int i = 0; i < (int)vt.size(); i++) {
        temp += vt[i];
        res = min(res, abs((d[b] - temp) - temp));
    }
    cout << res;

    return 0;
}