#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, a[302];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("socialise.inp", "r", stdin);
    freopen("socialise.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n+1] = INF;
    sort(a + 1, a + n + 1);

    for (int g = 1; g <= n; g++) {
        int x = INF;
        for (int r = g; r <= n; r++) {
            int l = r - g + 1;
            int tmp = (a[r] - a[l] + 2);
            if (tmp == 2) tmp--;
            if (a[l-1] / tmp != a[l] / tmp
                && a[r+1] / tmp != a[r] / tmp)
                x = min(x, tmp);
        }
        cout << ((x != INF) ? x : -1) << '\n';
    }

    return 0;
}