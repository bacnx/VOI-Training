#include<bits/stdc++.h>
using namespace std;

int n;
long long k, s[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("tank.inp", "r", stdin);
    freopen("tank.out", "w", stdout);

    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        long long a; cin >> a;
        s[i] = a + s[i-1];
    }

    int ans = 0;
    int l = 0, r = 0;

    while (r < n && s[r+1] < k) r++;
    ans = r - l;

    for (r++; r <= n; r++) {
        while (s[r] - s[l+1] >= k) l++;
        ans = max(ans, r - l);
    }

    cout << ans;

    return 0;
}