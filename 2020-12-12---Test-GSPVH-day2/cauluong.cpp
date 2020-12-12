#include<bits/stdc++.h>
using namespace std;

const int MAX = 1502;

int n, m;
int father[MAX];
vector<int> adj[MAX];
int lever[MAX];
int chil[MAX];

int sumChil(int u, int l) {
    lever[u] = l;
    int &ans = chil[u];
    for (int v : adj[u])
        ans += sumChil(v, l + 1);
    return ++ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("cauluong.inp", "r", stdin);
    freopen("cauluong.out", "w", stdout);

    int t; cin >> t;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        father[v] = u;
        adj[u].push_back(v);
    }
    
    sumChil(1, 1);
    for (int v = 2; v <= n; v++) {
        int u = father[v];
        int ans = lever[u] * chil[v];
        cout << ans << '\n';
    }

    return 0;
}