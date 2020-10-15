#include<bits/stdc++.h>
using namespace std;

int n, a[277][277];
bool keep[277][277];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("shortest.inp", "r", stdin);
    freopen("shortest.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            keep[i][j] = true;
        }

    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j) continue;
                if (a[i][j] == a[i][k] + a[k][j])
                    // a[i][j] = a[j][i] = INT_MAX;
                    keep[i][j] = keep[j][i] = false;
            }

    vector<pair<int, int>> v;
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            if (keep[i][j])
                v.push_back(pair<int, int>(i, j));
                // cout << i << ' ' << j << ' ' << a[i][j] << '\n';
    
    cout << (int)v.size() << '\n';
    for (auto i : v)
        cout << i.first << ' '<< i.second << ' ' << a[i.first][i.second] << '\n';

    return 0;
}