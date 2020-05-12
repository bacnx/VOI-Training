#include <bits/stdc++.h>
using namespace std;

int n, a[1000006];

int main()
{
    freopen("gtdayso.inp", "r", stdin);
    freopen("gtdayso.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int s = 0, mx = a[n];
    for (int i = n; i > 0; i--) {
        mx = max(mx, a[i]);
        s += mx;
    }
    
    cout << s;

    return 0;
}