#include<bits/stdc++.h>
using namespace std;

const int maxN = 501;

struct Edge {
    int u, v, cost;

    Edge(int _u = 0, int _v = 0, int _cost = 0) {
        u = _u, v = _v, cost = _cost;
    }
};

int numNode, numEdge;
Edge edges[100005];
vector<int> g[maxN];
int gra[maxN][maxN];
int numAff[100005];

long long dist[maxN][maxN];
int numPath[maxN][maxN];
int root[maxN][maxN];

void dijkstra(int s) {
    for (int i = 1; i <= numNode; i++) dist[s][i] = LLONG_MAX;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[s][s] = 0;
    numPath[s][s] = 1;
    root[s][s] = -1;
    pq.push(make_pair(0, s));

    while(!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dist[s][u]) continue;

        for (int i : g[u]) {
            int v = edges[i].u + edges[i].v - u;
            long long c = edges[i].cost;
            
            if (dist[s][v] > dist[s][u] + c) {
                dist[s][v] = dist[s][u] + c;
                pq.push(make_pair(dist[s][v], v));
                numPath[s][v] = numPath[s][u];
                root[s][v] = u;
            } else if (dist[s][v] == dist[s][u] + c) {
                numPath[s][v] += numPath[s][u];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);

    cin >> numNode >> numEdge;
    for (int i = 1; i <= numEdge; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges[i] = Edge(u, v, c);
        g[u].push_back(i);
        g[v].push_back(i);
        gra[u][v] = gra[v][u] = i;
    }

    for (int s = 1; s < numNode; s++) {
        dijkstra(s);
        for (int t = s+1; t <= numNode; t++) {
            int v = t, u = root[s][t];
            while (u != -1) {
                if (numPath[s][u] == numPath[s][v]) 
                    numAff[gra[u][v]]++;
                v = u;
                u = root[s][u];
            }
        }
    }

    for (int i = 1; i <= numEdge; i++)
        cout << numAff[i] << '\n';

    return 0;
}