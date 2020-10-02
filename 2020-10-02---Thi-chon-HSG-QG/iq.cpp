#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1e5+1;

int n, a[maxN], b[maxN];

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("iq.inp", "r", stdin);
    freopen("iq.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    int j = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[j]) {
            ans++;
            j++;
        }
    }
    cout << ans;

    return 0;
}
