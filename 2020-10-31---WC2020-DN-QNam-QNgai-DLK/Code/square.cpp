#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    freopen("square.inp", "r", stdin);
    freopen("square.out", "w", stdout);

    int k; cin >> k;
    if (k == 0) { cout << '0'; return 0; }

    int ans = LLONG_MAX;
    for (int i = -(int)sqrt(abs(k)); i <= (int)sqrt(abs(k)); i++) if (i && k % i == 0) {
        int a = i, b = k/i;
        if ((a + b) % 2 != 0) continue;
        int y = (a + b) / 2, x = max(a, b) - y;
        if (min(x, y) >= 0)
            ans = min(ans, y);
    }
    
    if (ans == LLONG_MAX) cout << "none";
    else cout << ans;

    return 0;
}