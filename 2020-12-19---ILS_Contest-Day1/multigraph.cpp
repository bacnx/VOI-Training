#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<ll, int> pli;
#define fi first
#define se second

const int MAX = 1e5 + 5;

int n;
int a[MAX];
vector<int> adj[MAX];

ll dijkstra(int u0, int v0) {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<ll> d(n + 1, 1e18);
    vector<bool> fre(n + 1, true);
    d[u0] = 0;
    pq.push(pli(0, u0));

    while (!pq.empty()) {
        int u = pq.top().se;
        ll _d = pq.top().fi;
        pq.pop();
        if (d[u] != _d || !fre[u]) continue;
        fre[u] = false;

        for (int v = 1; v <= n; v++) if (fre[v]) {
            ll w = 1LL * a[u] * a[v];
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(pli(d[v], v));
            }
        }
    }
    return d[v0];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("multigraph.inp", "r", stdin);
    freopen("multigraph.out", "w", stdout);

    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 1) a[u] = v;
        else cout << dijkstra(u, v) << '\n';
    }

    return 0;
}