#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 300005;

int n, m, a[MAX];

int query() {
    int l, r; cin >> l >> r;

    int optL = 0, optR = 0, mx = 0;
    for (int i = l; i <= r; i++) {
        int s = 0;
        for (int j = i; j <= r; j++) {
            s += a[j];
            if (s > mx) {
                mx = s;
                optL = i, optR = j;
            }
        }
    }

    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (optL <= i && i <= optR) a[i] = 0;
        s += a[i];
    }
    return s;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("magicians.inp", "r", stdin);
    freopen("magicians.ans", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    while (m--) ans += query();
    cout << ans;

    return 0;
}