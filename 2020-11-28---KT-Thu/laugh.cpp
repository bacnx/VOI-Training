#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("laugh.inp", "r", stdin);
    freopen("laugh.out", "w", stdout);

    int n; cin >> n;
    if (n != 1) return 0;
    string s; cin >> s;
    string p; cin >> p;

    int ans = 0;
    n = (int)s.size(); int m = (int)p.size();
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (cnt < n && s[cnt + i] == p[cnt % m]) cnt++;
        ans = max(ans, cnt - cnt % m);
    }
    cout << ans;

    return 0;
}