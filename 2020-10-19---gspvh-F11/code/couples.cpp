#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> aboveA, belowA, aboveB, belowB;
vector<pair<int, int>> ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("couples.inp", "r", stdin);
    freopen("couples.out", "w", stdout);

    int t; cin >> t;
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        int a; cin >> a;
        if (a < 0) belowA.push_back(make_pair(-a, i));
        else aboveA.push_back(make_pair(a, i));
    }
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a < 0) belowB.push_back(make_pair(-a, i));
        else aboveB.push_back(make_pair(a, i));
    }

    sort(aboveA.begin(), aboveA.end());
    sort(belowA.begin(), belowA.end());
    sort(aboveB.begin(), aboveB.end());
    sort(belowB.begin(), belowB.end());

    int j = 0;
    for (int i = 0; i < (int)belowA.size(); i++) {
        if (j == (int)aboveB.size()) break;
        if (belowA[i].first > aboveB[j].first) {
            ans.push_back(make_pair(belowA[i].second, aboveB[j].second));
            j++;
        }
    }
    j = 0;
    for (int i = 0; i < (int)belowB.size(); i++) {
        if (j == (int)aboveA.size()) break;
        if (belowB[i].first > aboveA[j].first) {
            ans.push_back(make_pair(aboveA[j].second, belowB[i].second));
            j++;
        }
    }

    cout << (int)ans.size() << '\n';
    for (auto i : ans)
        cout << i.first << ' ' << i.second << '\n';

    return 0;
}