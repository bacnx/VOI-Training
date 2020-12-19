#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 999999937

bool check(int x) {
    int tmp = x;
    while (tmp != 0) {
        if (tmp % 10 != 0 && x % (tmp % 10) != 0) return false;
        tmp /= 10;
    }
    return true;
}

int query(int n) {
    int _n = 1;
    for (int i = 1; i <= n; i++) _n *= 10;
    int ans = 1;
    for (int i = 1; i < _n; i++) if (check(i)) {
        ans ++;
    }
    return ans;
}

int ans[] = { 10, 33, 138, 752, 4578, 29951, 207198, 1495638, 11175107, 17112464 };

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("ndnum.inp", "r", stdin);
    freopen("ndnum.out", "w", stdout);
    
    int n; cin >> n;
    if (n <= 10) cout << ans[n-1];

    return 0;
}