#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1001;

int n, r, k, a[maxN][maxN];
int f[maxN][maxN];
bool sel[maxN][maxN];

void select(int x, int y) {
    for (int i = 0; x+i <= n && i < r; i++)
        f[x+i][y]++;
    if (y+r > n) return ;
    for (int i = 0; x+i <= n && i < r; i++)
        f[x+i][y+r]--;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);

    cin >> n >> r >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    while (k--) {
        int x, y; cin >> x >> y;
        select(x, y);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
                f[i][j] += f[i][j-1];
            if (f[i][j])
                ans += a[i][j];
            //cout << fx[i][j] << ' ';
        }
        //cout << '\n';
    }

    cout << ans;

    return 0;
}
