#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, b, l;
    Edge() {}
    Edge(int _u, int _v, int _b, int _l) {
        u = _u, v = _v, b = _b, l = _l;
    }
};

#define MAX 500005
const int MOD = 998244353;

int fact[MAX];

void initFact() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) fact[i] = (1LL * i * fact[i-1]) % MOD;
}

int n;
vector<int> adj[MAX];

vector<Edge> _e;
vector<int> _adj[MAX];
void read() {
    int t; cin >> t;
    int _n, _m; cin >> _n >> _m;

    for (int i = 1; i <= _m; i++) {
        int u, v, b, l; cin >> u >> v >> b >> l;
        _e.push_back(Edge(u, v, b, l));
        _adj[u].push_back((int)_e.size()-1);
    }

    n = _m;
    for (int i = 0; i < _m; i++) {
        int u = _e[i].u, v = _e[i].v, b = _e[i].b, l = _e[i].l;
        for (int j : _adj[v]) {
            int _b = _e[j].b, _l = _e[j].l;
            if (_b > b && _l > l) adj[i+1].push_back(j+1);
        }
    }
}

bool dd[MAX];

int count(int u, int i) {
    dd[u] = true;
    int ans = fact[i];
    for (int v : adj[u]) {
        ans += 1LL * (count(v, i+1) - fact[i]) % MOD;
        ans = ans % MOD;
    }
    return ans;
}

void solve () {
    long long ans = 0;
    for (int i = 1; i <= n; i++) if (dd[i] == false) {
        ans = (ans + count(i, 1)) % MOD;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("B.inp", "r", stdin);

    initFact();
    read();
    solve();

    return 0;
}