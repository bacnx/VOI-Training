#include<bits/stdc++.h>
using namespace std;

int n, r, k, a[550][550];
int f[550][550];

void choose(int x, int y) {
    for (int i = 0; i < r; i++)
        f[x+i][y] = r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);

    cin >> n >> r >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];

    while (k--) {
        int x, y; cin >> x >> y;
        choose(x, y);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        f[i][j] = max(f[i][j], f[i][j-1] - 1);
        if (f[i][j]) ans += a[i][j];
    }

    cout << ans;

    return 0;
}