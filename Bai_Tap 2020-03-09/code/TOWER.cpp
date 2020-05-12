#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6+6;
const int mod = 1e9+9;
ll n, d, a[maxn];

int32_t main()
{
    freopen("tower.inp", "r", stdin);
    freopen("tower.out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);

    ll res = 1, t = 1;
    queue<ll> q;
    for (int i = 1; i <= n; i++) {
        q.push(a[i]);
        while (q.front() + d < a[i]) q.pop();
        if ((int)q.size() == 1) { res = (res*t)%mod; t = 1; }
        t = (t * (ll)q.size()) % mod;
    }
    res = (res*t)%mod;
    cout << res;

    return 0;
}