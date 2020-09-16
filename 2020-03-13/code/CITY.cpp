#include <bits/stdc++.h>
using namespace std;

const int maxn = 1048;
int n, m;
vector<int> g[maxn];

bool dijkstra(int u0) {
    int x = n-1;
    vector<bool> avail(n+1, true);
    avail[u0] = false;
    queue<int> q;
    q.push(g[u0][0]);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (!avail[u]) continue;
        avail[u] = false;
        x--;
        for (int i = 0; i < (int)g[u].size(); i++)
            if (avail[g[u][i]]) q.push(g[u][i]);
    }
    return x != 0;
}

int main()
{
    freopen("city.inp", "r", stdin);
    freopen("city.out", "w", stdout);

    cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> result;
    for (int i = 1; i <= n; i++)
        if (dijkstra(i)) result.push_back(i);
    
    cout << result.size() << endl;
    for (int i = 0; i < (int)result.size(); i++)
        cout << result[i] << endl;

    return 0;
}