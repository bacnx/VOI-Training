#include<bits/stdc++.h>
using namespace std;

#define ll long long

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

struct Edge {
    int u, v, w, id;
    bool selected;
    Edge() {}
    Edge(int _u, int _v, int _w, int _id) {
        u = _u;
        v = _v;
        w = _w;
        id = _id;
        selected = false;
    }
};

bool cmp1(const Edge &a, const Edge &b) {
    return a.w != b.w ?
        a.w > b.w : a.id > b.id;
}
bool cmp2(const Edge &a, const Edge &b) {
    return a.w != b.w ?
        a.w < b.w : a.id < b.id;
}

const int MAX = 3e5 + 5;

int n, k, m, p;
vector<int> shop;
vector<Edge> e1, e2;

void kruskal() {
    DisjointSet ds(n);

    for (int i : shop) ds.merge(0, i);

    for (Edge &e : e1) if (!ds.isSame(e.u, e.v)) {
        ds.merge(e.u, e.v);
        e.selected = true;
    }
    for (Edge &e : e2) if (!ds.isSame(e.u, e.v)) {
        ds.merge(e.u, e.v);
        e.selected = true;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("moji.inp", "r", stdin);
    freopen("moji.out", "w", stdout);

    { int t; cin >> t; }
    cin >> n;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int a; cin >> a;
        shop.push_back(a);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e1.push_back(Edge(u, v, w, i));
    }
    cin >> p;
    for (int i = 1; i <= p; i++) {
        int u, v, w; cin >> u >> v >> w;
        e2.push_back(Edge(u, v, w, i));
    }
    
    sort(e1.begin(), e1.end(), cmp1);
    sort(e2.begin(), e2.end(), cmp2);

    kruskal();

    ll res = 0;
    vector<int> resLs1, resLs2;
    for (Edge e : e1) if (!e.selected) {
        res += e.w;
        resLs1.push_back(e.id);
    }
    for (Edge e : e2) if (e.selected) {
        res += e.w;
        resLs2.push_back(e.id);
    }
    sort(resLs1.begin(), resLs1.end());
    sort(resLs2.begin(), resLs2.end());

    cout << res << '\n';
    cout << resLs1.size() << '\n';
    for (int i : resLs1) cout << i << ' ';
    cout << '\n';
    cout << resLs2.size() << '\n';
    for (int i : resLs2) cout << i << ' ';
    cout << '\n';

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