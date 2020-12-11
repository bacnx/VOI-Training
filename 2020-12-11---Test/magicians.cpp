#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        f.resize(_n + 1, 0);
    }

    // update x -> y
    void update(int i, int x, int y) {
        while (i <= n) {
            f[i] += y - x;
            i += (i & -i);
        }
    }
    ll get(int i) {
        ll ans = 0;
        while (i >= 1) {
            ans += f[i];
            i -= (i & -i);
        }
        return ans;
    }
};

const int MAX = 3e5 + 5;

int n, m, a[MAX];
Fenwick fw;

ll query(int l, int r) {
    vector<int> f(n + 1, 0);
    vector<int> t(n + 1, 0);
    ll tmp = 0;

    for (int i = l; i <= r; i++) {
        int typeTmp = -(i - 1);
        if (tmp <= 0) {
            typeTmp = -1e9;
            tmp = a[i];
        } else tmp += a[i];

        if (f[i-1] > tmp) {
            f[i] = f[i-1];
            t[i] = i - 1;
        } else {
            f[i] = tmp;
            t[i] = typeTmp;
        }
    }

    int u = r;
    while (u != 1e9) {
        if (t[u] < 0 && a[u] != 0) {
            fw.update(u, a[u], 0);
            a[u] = 0;
        }
        u = t[u];
        if (u < 0) u = -u;
    }
    
    return fw.get(n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("magicians.inp", "r", stdin);
    freopen("magicians.out", "w", stdout);

    cin >> n >> m;
    fw = Fenwick(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fw.update(i, 0, a[i]);
    }

    ll ans = 0;
    while (m--) {
        int l, r; cin >> l >> r;
        ans += query(l, r);
    }
    cout << ans;

    return 0;
}