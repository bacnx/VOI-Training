#include <bits/stdc++.h>
using namespace std;

const int maxn = 10004;
const int oo = 1e7+7;
typedef pair<int, int> pii;
int n, k, d[maxn];
vector<pii> g[maxn];

void dijkstra() {
    for (int i = 1; i <= n; i++)
        d[i] = oo*100;
    d[1] = 0;
    vector<bool> avail(n, true);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, 1));

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (!avail[u]) continue;
        avail[u] - false;

        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].first, w = g[u][i].second;
            if (!avail[v]) continue;

            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push(pii(d[v], v));
            }
        }
    }

    if (d[n] == oo*100) cout << "-1";
    else cout << d[n] % oo << endl << d[n] / oo;
}

int main()
{
    freopen("td.inp", "r", stdin);
    freopen("td.out", "w", stdout);

    cin >> n >> k;
    int u, v, w;
    for (int i = 1; i <= k; i++) {
        cin >> u >> v;
        g[u].push_back(pii(v, oo));
        g[v].push_back(pii(u, oo));
    }
    while (true) {
        u = 0;
        cin >> u >> v >> w;
        if (u == 0) break;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }

    dijkstra();

    return 0;
}