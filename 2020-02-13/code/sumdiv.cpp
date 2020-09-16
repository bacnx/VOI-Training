#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+1;
int n, t, a[maxn], st[4*maxn];

int uoc(int a) {
    for (int i = 2; i <= (int)sqrt(a); i++)
        if (a % i == 0) return i;
    return a;
}

void update(int id, int l, int r, int i, int v) {
    if (i < l || i > r) return ;
    if (l == r) { st[id] = v; return ; }

    int mid = (l + r)/2;
    update(id*2, l, mid, i, v);
    update(id*2+1, mid+1, r, i, v);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return 0;
    if (u <= l && v >= r) return st[id];

    int mid = (l + r)/2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

int32_t main()
{
    freopen("sumdiv.inp", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 1, n, i, uoc(a[i])+1);
    }
    
    int l, r;
    while (t--) {
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << endl;
    }

    return 0;
}