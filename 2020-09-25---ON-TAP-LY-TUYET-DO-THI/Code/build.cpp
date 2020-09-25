#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
const int nMax = 101;

int n, u[4];
pii d[nMax][nMax];
bool fre[nMax][nMax];
int ans = 0;
vector<pii> ansArr;
int r[nMax];

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j].first = INT_MAX;
            d[i][j].second = 0;

            fre[i][j] = true;
        }
        d[i][i].first = 0;
        r[i] = -1;
    }
}

int root(int u) {
    if (r[u] == -1) 
        return u;
    else return root(r[u]);
}

void select(pii a) {
    int u = a.first, v = a.second, k = d[u][v].second;
    if (!fre[u][v]) return ;
    fre[u][v] = fre[v][u] = false;

    if (k == 0) {
        ansArr.push_back(a);
        ans += d[u][v].first;
    } else {
        select(pii(u, k));
        select(pii(k, v));
    }
}

int32_t main() {
    freopen("build.inp", "r", stdin);
    freopen("build.out", "w", stdout);

    cin >> n;
    cin >> u[0] >> u[1] >> u[2] >> u[3];

    init();
    
    while (true) {
        int u, v, c = -1; cin >> u >> v >> c;
        if (c == -1) break;
        d[u][v].first = d[v][u].first = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j].first > d[i][k].first + d[k][j].first) {
                    d[i][j].first = d[i][k].first + d[k][j].first;
                    d[i][j].second = k;
                }
            }
        }
    }

    vector<ppi> v;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            int a = u[i], b = u[j];
            v.push_back(ppi(d[a][b].first, pii(a, b)));
            // cout << a << ' ' << b << ' ' << d[a][b].first << ' ' << d[a][b].second << '\n';
            // cout << v.back().second.first << ' ' << v.back().second.second << ' ' << v.back().first << '\n';
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); i++) {
        int a = v[i].second.first, b = v[i].second.second;
        if (root(a) != root(b)) {
            select(v[i].second);
            r[max(a, b)] = min(a, b);
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < (int)ansArr.size(); i++)
        cout << ansArr[i].first << ' ' << ansArr[i].second << '\n';

    return 0;
}