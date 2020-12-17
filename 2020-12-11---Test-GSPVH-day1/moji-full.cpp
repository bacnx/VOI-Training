#include<bits/stdc++.h>
using namespace std;

struct DisjointSet {
    int n;
    vector<int> par;
    DisjointSet() {}
    DisjointSet(int _n) {
        n = _n;
        par.assign(n + 1, -1);
    }

    int root(int v) {
        return par[v] < 0
            ? v
            : root(par[v] = root(par[v]));
    }

    void merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return ;

        if (par[y] < par[x]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool isSame(int x, int y) {
        return ((x = root(x)) == (y = root(y)));
    }
};

const int MAX = 3e5 + 5;

int n, k, m;
vector<int> p;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("moji.inp", "r", stdin);
    freopen("moji.out", "w", stdout);

    { int t; cin >> t; }
    cin >> n;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int a; cin >> a;
        p.push_back(a);
    }

    // int n; cin >> n;
    // DisjointSet ds(n);

    // while (true) {
    //     int t, u, v; cin >> t;
    //     if (t == -1) break;
    //     cin >> u >> v;

    //     if (t == 1) ds.merge(u, v);
    //     else cout << ds.isSame(u, v) << endl;
    // }

    return 0;
}