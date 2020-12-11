#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, l, id;
    Edge() {}
    Edge(int _u, int _v, int _l, int _id) {
        u = _u, v = _v, l = _l, id = _id;
    }
};

typedef pair<int, int> pii;
const int MAX = 3e5 + 5;
const int INF = 1e9 + 7;

int n, k, m, p;
vector<int> root;
vector<Edge> e1, e2;

vector<pii> adj[MAX];
int t[MAX];
int a[MAX];

void makeTree() {
    priority_queue<pii> pq;
    vector<int> d(n + 1, -INF);
    vector<bool> fre(n + 1, true);
    for (int u : root) {
        pq.push(pii(INF, u));
        d[u] = INF;
    }

    while (!pq.empty()) {
        int u = pq.top().second, l = pq.top().first; pq.pop();
        // cout << u << ' ' << l << '\n';
        if (!fre[u] || l != d[u]) continue;
        fre[u] = false;

        for (pii i : adj[u]) {
            int v = i.first, w = i.second;
            if (!fre[v]) continue;

            if (d[v] < w) {
                d[v] = w;
                t[v] = u;
                pq.push(pii(w, v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("moji.inp", "r", stdin);
    freopen("moji.out", "w", stdout);

    {int t; cin >> t;}
    cin >> n;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int u; cin >> u;
        root.push_back(u);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, l; cin >> u >> v >> l;
        if (u > v) swap(u, v);
        e1.push_back(Edge(u, v, l, i));

        adj[u].push_back(pii(v, l));
        adj[v].push_back(pii(u, l));
    }
    cin >> p;
    for (int i = 1; i <= p; i++) {
        int u, v, l; cin >> u >> v >> l;
        if (u > v) swap(u, v);
        e2.push_back(Edge(u, v, l, i));

        adj[u].push_back(pii(v, -l));
        adj[v].push_back(pii(u, -l));
    }

    makeTree();

    map<pii, int> mp;
    for (int i = 1; i <= n; i++) {
        int u = i, v = t[i];
        if (u > v) swap(u, v);
        mp[pii(u, v)] = 1;
    }

    int res = 0;
    vector<int> ans1, ans2;
    for (Edge i : e1) {
        int u = i.u, v = i.v, l = i.l;
        if (mp.find(pii(u, v)) == mp.end()) {
            res += l;
            ans1.push_back(i.id);
        }
    }
    for (Edge i : e2) {
        int u = i.u, v = i.v, l = i.l;
        if (mp.find(pii(u, v)) != mp.end()) {
            res += l;
            ans2.push_back(i.id);
        }
    }
    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());

    cout << res << '\n';
    cout << (int)ans1.size() << '\n';
    for (int i : ans1) cout << i << ' ';
    cout << '\n';
    cout << (int)ans2.size() << '\n';
    for (int i : ans2) cout << i << ' ';
    cout << '\n';

    return 0;
}