#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1e5+1;
int n, m;
pair<int, int> a[maxN];
int sumW[maxN], sumDW[maxN];

void initSum() {
    for (int i = 1; i <= n; i++)
        sumW[i] = sumW[i-1] + a[i].second;
    for (int i = 1; i <= n; i++)
        sumDW[i] = sumDW[i-1] + a[i].first * a[i].second;
}
int getSumW(int i, int j) {
    if (i > j) return 0;
    return sumW[j] - sumW[i-1];
}
int getSumDW(int i, int j) {
    if (i > j) return 0;
    return sumDW[j] - sumDW[i-1];
}

int query(int p) {
    int k = upper_bound(a+1, a+n+1, make_pair(p, (long long)0)) - a;
    int ans = getSumDW(1, k-1) - getSumW(1, k-1) * p;
    ans += getSumW(k, n) * p - getSumDW(k, n);
    return -ans;
}

int32_t main() {
    freopen("talent.inp", "r", stdin);
    freopen("talent.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second;

    sort(a+1, a+n+1);
    initSum();
    
    while (m--) {
        int p; cin >> p;
        cout << query(p) << '\n';
    }

    return 0;
}