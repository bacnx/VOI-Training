#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 100005;

int n, a[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("evensub.inp", "r", stdin);
    freopen("evensub.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll res = 0LL;
    for (int i = 1; i <= n; i++) {
        int mn = a[i], mx = a[i];
        for (int j = i; j <= n; j++) {
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            if ((mx & 1) == (mn & 1)) res++;
        }
    }

    cout << res;

    return 0;
}