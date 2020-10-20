#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[2002][2002];

long long sm(int i, int j) {
    long long ans = 0;
    if (a[i][j] > a[i-1][j]) ans += a[i][j] - a[i-1][j];
    if (a[i][j] > a[i+1][j]) ans += a[i][j] - a[i+1][j];
    if (a[i][j] > a[i][j-1]) ans += a[i][j] - a[i][j-1];
    if (a[i][j] > a[i][j+1]) ans += a[i][j] - a[i][j+1];
    return ans;
}

int32_t main() {
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);// cin >> a[i][j];
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += sm(i, j);
            if (a[i][j]) ans++;
        }
    }
    cout << ans;

    return 0;
}
