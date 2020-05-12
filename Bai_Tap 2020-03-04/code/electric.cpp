#include <bits/stdc++.h>
using namespace std;

struct point { int x, y, w; };
struct edge { int u, v, w; };
int n, k;
point p[402];
vector<edge> e;    // edge e[100005];
vector<int> fat(202, -1);

bool cmp(const edge &u, const edge &v) { return u.w < v.w; };

void pushe(int u, int v) {
    edge t;
    t.w = p[u].w + p[v].w + abs(p[u].x-p[v].x) + abs(p[u].y-p[v].y);
    t.u = u, t.v = v;
    if (u > n) t.u = 0;
    e.push_back(t);
}

void test() {
    for (int i = 0; i < (int)e.size(); i++)
        cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
}

void make_edge() {
    for (int i = 1; i <= n; i++)
        p[i].w = 0;
    for (int i = n+1; i <= n+k; i++)
        for (int j = 1; j <= n; j++)
            pushe(i, j);
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            pushe(i, j);
    // test();
}

int find_fat(int u) {
    if (fat[u] == -1) return u;
    return find_fat(fat[u]);
}

void kruskal() {
    int res = 0;
    for (int i = 0, j = 0; j < n; i++) {
        int u = find_fat(e[i].u), v = find_fat(e[i].v);
        if (u != v) {
            j++;
            fat[max(u, v)] = min(u, v);
            res += e[i].w;
            // cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
            // cout << u << " " << v << endl;
        }
    }
    cout << res;
}

int main()
{
    freopen("electric.inp", "r", stdin);
    freopen("electric.out", "w", stdout);

    cin >> k >> n;
    for (int i = 1; i <= k; i++)
        cin >> p[n+i].x >> p[n+i].y >> p[n+i].w;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    
    make_edge();
    sort(e.begin(), e.end(), cmp);
    kruskal();

    return 0;
}