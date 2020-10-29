#include<bits/stdc++.h>
using namespace std;

struct Query {
    int a, b, c;
};

int k, m, n;
string s;
Query q[200005];

int query(int k) {
    for (int i = n - 1; i >= 0; i--) {
        int a = q[i].a, b = q[i].b, c = q[i].c;
        if (k < c) continue;
        if (k >= c + (b - a)) k -= b - a;
        else k -= c - a;
    }
    return k;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("fasttype.inp", "r", stdin);
    freopen("fasttype.out", "w", stdout);

    cin >> k >> m;
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i].a >> q[i].b >> q[i].c;

    for (int i = 0; i < k; i++) cout << s[query(i)];

    return 0;
}