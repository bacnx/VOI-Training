#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
const int nMax = 5001;

int n, m;
vector<pii> g[nMax];
int d[nMax];
pii t[nMax];

void solve() {
    for (int i = 1; i <= n; i++) {
        d[i] = LLONG_MAX - n*INT_MAX;
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<bool> fre(n+1, true);

    d[1] = 0;
    pq.push(pii(d[1], 1));

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (!fre[u]) continue;
        fre[u] = false;

        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].first, w = g[u][i].second;
            if (!fre[v]) continue;
            if (d[v] == d[u] + w) {
                t[v].second ++;
            } else if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                t[v].first = u;
                t[v].second = 1;
                pq.push(pii(d[v], v));
            }
        }
    }
}

int cnt(int u) {
    int ans = 1;
    while (u != 1) {
        ans *= t[u].second;
        u = t[u].first;
    }
    return ans;
}

int32_t main() {
    freopen("school.inp", "r", stdin);
    freopen("school.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int k, u, v, l; 
        cin >> k >> u >> v >> l;

        g[u].push_back(pii(v, l));
        if (k == 2)
            g[v].push_back(pii(u, l));
    }

    solve();

    cout << d[n] << ' ' << cnt(n);

    return 0;
}