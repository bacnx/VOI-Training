#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1e5+1;

int n, k, a[maxN];
int s = 0;

int32_t main() {
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    k %= s;
    
    for (int i = 0; i < n; i++)
        if (k >= a[i]) k -= a[i];
        else break;

    cout << k;

    return 0;
}