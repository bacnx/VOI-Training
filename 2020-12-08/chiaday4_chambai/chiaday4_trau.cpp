#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 100005;

int n, a[MAX];
ll s[MAX];

ll get(int l, int r) {
    if (l > r) return 0;
    return s[r] - s[l-1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("chiaday4.inp", "r", stdin);
    freopen("chiaday4.ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];

    ll res = 0;
    for (int x = 1; x <= n + 1; x++)
    for (int y = x; y <= n + 1; y++)
    for (int z = y; z <= n + 1; z++) {
        ll tmp = get(1, x-1) - get(x, y-1)
                + get(y, z-1) - get(z, n);
        res = max(res, tmp);
    }
    cout << res;

    return 0;
}