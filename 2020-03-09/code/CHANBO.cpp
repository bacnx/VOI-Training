#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+2;
int n, c, a[maxn], kc[maxn];

bool check(int k) {
    int res = 1, t = a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] - t >= k) { res++; t = a[i]; }
    return res >= c;
}

int main()
{
    freopen("chanbo.inp", "r", stdin);
    // freopen("chanbo.out", "w", stdout);

    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);

    int res = 0;
    int l = a[1], r = a[n], mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (check(mid)) { res = mid; l = mid + 1; }
        else r = mid - 1;
    }
    
    cout << res;

    return 0;
}