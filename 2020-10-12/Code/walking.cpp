#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1e5;

struct studen {
    int index, t0, t;
};

int n, l;
studen a[maxN];
int id[maxN], t[maxN];

bool cmp(const studen &a, const studen &b) {
    if (a.t0 != b.t0) return a.t0 < b.t0;
    else return a.t > b.t;
}

int32_t main() {
    freopen("walking.inp", "r", stdin);
    freopen("walking.out", "w", stdout);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i].t0 >> a[i].t;
        a[i].index = i;
    }
    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++) {
        t[i] = a[i].t0 + l * a[i].t;
        id[a[i].index] =  i;
    }

    for (int i = 1; i < n; i++)
        if (t[i] < t[i-1]) t[i] = t[i-1];
    
    for (int i = 0; i < n; i++)
        cout << t[id[i]] << '\n';

    return 0;
}