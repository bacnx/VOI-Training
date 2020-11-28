#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 100005;

int n, a[MAX], b[MAX];
ll Fa[MAX], Fb[MAX];
int t[2][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("riceatm.inp", "r", stdin);
    freopen("riceatm.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    Fb[0] = 1e9;
    for (int i = 1; i <= n; i++) {
        if (Fa[i-1] + (ll)a[i] <= Fb[i-1]) {
            Fa[i] = Fa[i-1] + (ll)a[i];
            t[0][i] = 1;
        } else {
            Fa[i] = Fb[i-1];
            t[0][i] = 0;
        }

        Fb[i] = Fa[i-1] + (ll)b[i];
        t[1][i] = 2;
    }

    /* trace */ vector<int> v(n, 0); {
        int sta = 0;
        for (int i = n; i >= 1; i--) {
            v[i-1] = t[sta][i];
            if (t[sta][i] == 2 || t[sta][i] == 1) sta = 0;
            else sta = 1;
        }
    }

    cout << Fa[n] << '\n';
    for (int u : v) cout << u << ' ';

    return 0;
}