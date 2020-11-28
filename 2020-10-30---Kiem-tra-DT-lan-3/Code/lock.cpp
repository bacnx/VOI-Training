#include<bits/stdc++.h>
using namespace std;

int n, k, s, a[100005];
vector<vector<int> > group;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("lock.inp", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int g = i % s;
        if ((int)group.size() < g+1) group.push_back(vector<int>());

        if (g == n % s) group[0].push_back(a[i]);
        else group[g].push_back(a[i]);
    }

    int ans = 0;
    for (int i = 0; i < (int)group.size(); i++) {
        sort(group[i].begin(), group[i].end());
        int mid = ((int)group[i].size()+1)/2 - 1;

        for (int j = 0; j < (int)group[i].size(); j++) 
            ans += abs(group[i][mid] - group[i][j]);
    }

    cout << ans;

    return 0;
}