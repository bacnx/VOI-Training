#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX

int n, k, a[1000006];

int sumK[1000006];
int maxLeft[2000006], maxRight[2000006];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        sumK[i] = a[i] + sumK[i-1];
        if (i > k) sumK[i] -= a[i-k];
    }

    for (int i = k; i <= n; i++)
        maxLeft[i] = max(sumK[i], maxLeft[i-1]);
    for (int i = n; i >= k; i--)
        maxRight[i] = max(sumK[i], maxRight[i+1]);

    int ans = INF;
    for (int i = k; i <= n; i++)
        ans = min(ans, max(maxLeft[i-k], maxRight[i+k]));

    cout << ans;

    return 0;
}