#include<bits/stdc++.h>
using namespace std;

struct egde { int u, v, w; };
const int maxn = 10004;
int n, k, vt, vk, w[maxn];
pair<long long, int> slen[maxn];
egde e[2*maxn];
vector<int> g[maxn];
queue<int> q;

void test() {
    for (int i = 1; i <= n; i++)
        cout << w[i] << " ";
    cout << endl;
}

void solve() {
    for (int i = 1; i <= n; i++)
        if (w[i] == 1) q.push(i);
    // test();

    while ((int)q.size() > 1) {
        int u = q.front(); q.pop();
        // cout << u << endl;
        int d = 1, vs;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int j = g[u][i];
            int v = e[j].v;
            if (w[v] == 0) d += slen[j%n].first;
            else {
                w[u]--; w[v]--;
                if (w[v] == 1) q.push(v);
                vs = j;
            }
        }
        slen[vs%n].first = (long long)d;
        // test();
    }

    for (int i = 1; i < n; i++) {
        slen[i].first = slen[i].first * (n-slen[i].first) * (long long)e[i].w;
        slen[i].second = i;
        // cout << slen[i].first << endl;
    }
    sort(slen+1, slen+n, greater<pair<int, int> >());
    for (int i = 1; i <= k; i++)
        cout << slen[i].second << endl;
}

int main()
{
    freopen("cau.inp", "r", stdin);
    freopen("cau.out", "w", stdout);

    cin >> n >> k >> vt >> vk;
    for (int i = 1; i < n; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        g[e[i].u].push_back(i);
        e[n+i] = e[i];
        swap(e[n+i].u, e[n+i].v);
        g[e[n+i].u].push_back(n+i);
    }
    for (int i = 1; i <= n; i++)
        w[i] = (int)g[i].size();

    solve();

    return 0;
}