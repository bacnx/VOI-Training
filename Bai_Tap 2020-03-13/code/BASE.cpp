#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
const int maxn = 1e5+5;
int n, m, r, f[maxn], g[maxn], a[maxn];
vector<pii> am;
int ar[maxn];

int32_t main()
{
    freopen("base.inp", "r", stdin);
    freopen("base.out", "w", stdout);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int q, p;
    for (int i = 1; i <= m; i++) {
        cin >> q >> p;
        am.push_back(pii(p, q));
    }
    for (int i = 1; i <= r; i++)
        cin >> ar[i];
    
    sort(a+1, a+n+1, greater<int>());
    sort(am.begin(), am.end());
    sort(ar+1, ar+r+1, greater<int>());

    for (int i = 1; i <= n && !am.empty(); i++) {
        int temp = a[i];
        f[i] = f[i-1];
        while (temp > 0 && !am.empty()) {
            if (temp < am.back().second) {
                f[i] += temp*am.back().first;
                am.back().second -= temp;
                temp = 0;
            }
            else {
                f[i] += am.back().second*am.back().first;
                temp -= am.back().second;
                am.pop_back();
            }
        }
    }
    for (int i = 1; i <= r; i++)
        g[i] = g[i-1] + ar[i];
    
    int res = 0;
    for (int i = 0; i <= n; i++)
        res = max(res, f[i] + g[n-i]);
    cout << res;

    return 0;
}