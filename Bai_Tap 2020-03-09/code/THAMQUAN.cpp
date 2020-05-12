#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;
typedef pair<int, int> pii;
int n, e, q, d[maxn];
vector<pii> g[maxn];

void dijsktra() {
    d[1] = 1e9;
    priority_queue<pii, vector<pii> > pq;
    vector<bool> avail(n+1, true);
    pq.push(pii(d[1], 1));
    
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (!avail[u]) continue;
        avail[u] = false;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].first, w = g[u][i].second;
            if (!avail[v]) continue;
            
            if (d[v] < min(d[u], w)) {
                d[v] = min(d[u], w);
                pq.push(pii(d[v], v));
            }
        }
    }
}

int main()
{
    freopen("thamquan.inp", "r", stdin);
    freopen("thamquan.out", "w", stdout);

    cin >> n >> e >> q;
    
    int u, v, w;
    for (int i = 1; i <= e; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }

    dijsktra();

    while (q--) {
        cin >> u;
        cout << d[u] << endl;
    }

    return 0;
}