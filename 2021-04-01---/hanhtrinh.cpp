#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, w, h;
    Edge() {}
    Edge(int _v, int _w, int _h) {
        v = _v, w = _w, h = _h;
    }
};

struct State {
    int u, w, h;
    State() {}
    State(int _u, int _w, int _h) {
        u = _u, w = _w, h = _h;
    }

    bool operator < (const State &b) const {
        return w > b.w;
    }
};

const int maxN = 10004;

int k, n, m;
vector<Edge> adj[maxN];

int d[maxN][202];

void dijkstra(int u0) {
    memset(d, -1, sizeof d);
    priority_queue<State> pq;
    d[u0][0] = 0;
    pq.push(State(u0, 0, 0));

    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        int u = cur.u, w = cur.w, h = cur.h;
        if (w != d[u][h]) continue;
        
        for (Edge e : adj[u]) {
            int v = e.v;
            State nxt(v, w + e.w, h + e.h);
            if (nxt.h >= k) continue;
            if (d[v][nxt.h] == -1 || d[v][nxt.h] > nxt.w) {
                d[v][nxt.h] = nxt.w;
                pq.push(nxt);
            }
        }
    }
}

int main() {
    freopen("hanhtrinh.inp", "r", stdin);
    freopen("hanhtrinh.out", "w", stdout);

    cin >> k >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w, h; cin >> u >> v >> w >> h;
        adj[u].push_back(Edge(v, w ,h));
        adj[v].push_back(Edge(u, w, h));
    }
    int a, b; cin >> a >> b;

    dijkstra(a);
    int res = 2e9;
    for (int h = 0; h < k; h++) if (d[b][h] != -1) {
        res = min(res, d[b][h]);
    }
    if (res == 2e9) res = -1;
    cout << res;

    return 0;
}