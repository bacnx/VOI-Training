#include<bits/stdc++.h>
using namespace std;

int n;
long long a[1000000], t, s;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);

    cin >> n;
    s = 0;
    for (int i = 0; i < n; i++) {
        // cin >> a[i];
        scanf("%lld", &a[i]);
        s += a[i];
    }
    t = s / n;

    s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < t) s += t - a[i];
    }
    cout << s;

    return 0;
}