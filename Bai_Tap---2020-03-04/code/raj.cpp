#include <bits/stdc++.h>
using namespace std;

int n, m, s, d, a[200005];

int main()
{
    freopen("raj.inp", "r", stdin);
    freopen("raj.out", "w", stdout);

    cin >> n >> m >> s >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = -1; a[n+1] = 2000000009;
    sort(a+1, a+n+1);
    
    int r = 0, j = 0, st = 0, en;
    for (int i = 1; i <= n+1; i++) {
        if (a[i] - a[i-1] - 2 >= s) {
            if (a[i-1]+1 - st > d) { cout << "-1"; return 0; }
            j += a[i-1]+1 - st;
            st = a[i] - 1;
        }
    }
    cout << m-j << " " << j;

    return 0;
}