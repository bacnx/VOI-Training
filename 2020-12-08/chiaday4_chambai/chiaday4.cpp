#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 100005;

int n, a[MAX];
ll fMin[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("chiaday4.inp", "r", stdin);
    freopen("chiaday4.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp = min(1LL * a[i], tmp + a[i]);
        fMin[i] = min(fMin[i-1], tmp);
    }
    tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += a[i];
        fMin[i] = tmp - fMin[i] * 2;
    }

    ll s = 0;
    ll res = 0;
    for (int i = n; i >= 0; i--) {
        res = max(res, fMin[i] - s);
        s += a[i];
    }
    cout << res;

    return 0;
}