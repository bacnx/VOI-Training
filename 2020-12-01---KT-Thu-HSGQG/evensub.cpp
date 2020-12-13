#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 100005;

int n, a[MAX];
int maxL[MAX], minL[MAX], maxR[MAX], minR[MAX];
int cntL[MAX], cntR[MAX];

ll solve(int l, int r) {
    if (l == r) return 1LL;
    int mid = (l + r) / 2;

    maxL[mid] = minL[mid] = a[mid];
    for (int i = mid - 1; i >= l; i--) {
        maxL[i] = max(maxL[i+1], a[i]);
        minL[i] = min(minL[i+1], a[i]);
    }
    maxR[mid+1] = minR[mid+1] = a[mid+1];
    for (int i = mid + 2; i <= r; i++) {
        maxR[i] = max(maxR[i-1], a[i]);
        minR[i] = min(minR[i-1], a[i]);
    }
    cntR[mid] = 0;
    for (int i = mid + 1; i <= r; i++) {
        cntR[i] = cntR[i-1] + (minR[i] % 2 == 0);
    }
    cntL[mid+1] = 0;
    for (int i = mid; i >= l; i--) {
        cntL[i] = cntL[i+1] + (minL[i] % 2 == 0);
    }

    ll ans = 0LL;
    int i = mid, j = mid, js = mid;
    for (; i >= l; i--) {
        while (j != r && maxL[i] >= maxR[j+1]) j++;
        if (j == mid) continue;
        while (js != j && minL[i] <= minR[js+1]) js++;

        ans += ((maxL[i] - minL[i]) % 2 == 0) * (js - mid);
        if (maxL[i] & 1) ans += (j - js) - (cntR[j] - cntR[js]);
        else ans += cntR[j] - cntR[js];
        // cout << j << ' ' << js << ' ' << cnt[j] << ' ' << cnt[js] << '\n';
    }
    i = mid + 1, j = mid + 1, js = mid + 1;
    for (; i <= r; i++) {
        while (j != l && maxR[i] > maxL[j-1]) j--;
        if (j == mid + 1) continue;
        while (js != j && minR[i] <= minL[js+1]) js--;

        ans += ((maxR[i] - minR[i]) % 2 == 0) * (mid - js + 1);
        if (maxR[i] & 1) ans += (js - j) - (cntL[j] - cntL[js]);
        else ans += cntL[j] - cntL[js];
    }
    cout << l << ' ' << r << '\n';
    cout << ans << '\n';
    return ans + solve(l, mid) + solve (mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("evensub.inp", "r", stdin);
    freopen("evensub.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // ll res = solve(1, n);
    // cout << res;
    cout << solve(1, 3);

    return 0;
}