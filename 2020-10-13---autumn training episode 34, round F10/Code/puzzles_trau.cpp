#include<bits/stdc++.h>
using namespace std;

int n;
string a[700005];

int check(int t) {
    vector<string> v;
    for (int i = 0; i < n; i++)
        if (t & (1<<i))
            v.push_back(a[i]);
    int ans = v[0].size();
    for (int i = 1; i < v.size(); i++) {
        if (v[i-1].back() != v[i].front())
            return 0;
        ans += v[i].size();
    }
    if (v.back().back() != v.front().front())
        return 0;
    return ans;
}

int main() {
    freopen("puzzles.inp", "r", stdin);
    freopen("puzzles.ans", "w", stdout);

    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    
    int ans = 0;
    for (int i = 1; i < (1<<n); i++)
        ans = max(ans, check(i));
    cout << ans;

    return 0;
}