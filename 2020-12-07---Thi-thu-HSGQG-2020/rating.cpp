#include<bits/stdc++.h>
using namespace std;

const int MAX = 300005;

int n, a[MAX];

void solveSub1() {
    cin >> n;
    int q; cin >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--) {
        int x, l, r; cin >> x >> l >> r;
        for (int i = l; i <= r; i++) x = abs(x - a[i]);
        cout << x << '\n';
    }
}

void solveSub2() {
    cin >> n;
    int q; cin >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    while (q--) {
        int x, l, r; cin >> x >> l >> r;
        x -= a[r] - a[l-1];
        cout << x << '\n';
    }
}

void solveSub3() {
    cin >> n;
    int q; cin >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--) {
        int x, l, r; cin >> x >> l >> r;
        int c = x / a[1]; 
        int num = r - l + 1;
        int res;

        if (c >= num) res = x - a[1] * num;
        else if ((num - c) % 2 == 0) res = x % a[1];
        else res = a[1] - x % a[1];
        cout << res << '\n';
    }
}

void solveSub4() {
    solveSub2();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("rating.inp", "r", stdin);
    freopen("rating.out", "w", stdout);

    int t; cin >> t;

    if (t == 1) solveSub1();
    if (t == 2) solveSub2();
    if (t == 3) solveSub3();
    if (t == 4) solveSub4();

    return 0;
}