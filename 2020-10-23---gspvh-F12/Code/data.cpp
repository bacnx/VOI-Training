#include<bits/stdc++.h>
using namespace std;

int n, x, a[10004];

int main() {
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1, a+n+1, greater<int>());

    int ans = 0;
    int i = 1, j = n;
    while (i <= j) {
        if (a[i] + a[j] <= x) j--;
        i++;
        ans++;
    }
    
    cout << ans;

    return 0;
}