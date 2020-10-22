#include<bits/stdc++.h>
using namespace std;

const int maxN = 1010;

int m, n, a[maxN][maxN];
int f[maxN][maxN];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("building.inp", "r", stdin);
    freopen("building.out", "w", stdout);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    
    for (int x = 1; x <= m; x++) {
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (a[x][i] < mx)
                f[x][i] = f[x][i] | (1<<3);
            mx = max(mx, a[x][i]);
        }
        mx = 0;
        for (int i = n; i >= 1; i--) {
            if (a[x][i] < mx)
                f[x][i] = f[x][i] | (1<<1);
            mx = max(mx, a[x][i]);
        }
    }
    for (int x = 1; x <= n; x++) {
        int mx = 0;
        for (int i = 1; i <= m; i++) {
            if (a[i][x] < mx)
                f[i][x] = f[i][x] | (1<<0);
            mx = max(mx, a[i][x]);
        }
        mx = 0;
        for (int i = m; i >= 1; i--) {
            if (a[i][x] < mx)
                f[i][x] = f[i][x] | (1<<2);
            mx = max(mx, a[i][x]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (f[i][j] == (1<<4)-1) ans ++;
    
    cout << ans;

    return 0;
}