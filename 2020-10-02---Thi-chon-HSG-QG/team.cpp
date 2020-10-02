#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1e5+1;

int n, k, a[maxN];

int32_t main() {
    freopen("team.inp", "r", stdin);
    freopen("team.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    k %= sum;
    for (int i = 0; i < n; i++) {
        if (k < a[i])
            break;
        k -= a[i];
    }
    cout << k;

    return 0;
}
