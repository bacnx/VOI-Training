#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 1003
typedef pair<int, int> pii;

int n, m, a[MAX];
vector<pair<int, int>> g[MAX];
int d[MAX];

int dijkstra(int u0) {
    for (int i = 2; i <= n; i++) d[i] = LLONG_MAX;
    d[1] = a[1];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(d[0], 0));

    while (!pq.empty()) {
        int u = pq.top().second, val = pq.top().first; pq.pop();
        if (val != d[u]) continue;
        u++;
        if (u == n) break;

        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].first, w = g[u][i].second;
            
            if (d[u-1] + w < d[v]) {
                d[v] = d[u-1] + w;
                pq.push(pii(d[v], v));
            }
        }
    }
    return d[n];
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        int sum = 0, mx = 0;
        for (int j = i; j <= n; j++) {
            sum += a[j];
            mx = max(mx, a[j]);
            if (sum <= m) g[i].push_back(make_pair(j, mx));
            else break;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i];
    ans -= dijkstra(1);

    cout << ans;

    return 0;
}