#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("tank.inp", "r", stdin);
    freopen("tank.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    int ans = n;
    for (int i = 1; i <= n; i++) {
        auto it = upper_bound(a+1, a+n+1, a[i-1] + m);
        if (it == a+n+1) break;
        ans = min(ans, (int)(it - a) - (i - 1));
    }
    cout << ans;

    return 0;
}