#include <bits/stdc++.h>
using namespace std;

int n, a[2003];
vector<int> v;

int main()
{
    freopen("tiahoa.inp", "r", stdin);
    freopen("tiahoa.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    v.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (a[i] > v.back()) v.push_back(a[i]);
        else v[lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
    }
    int t = (int)v.size();
    v.clear();
    v.push_back(a[n]);
    for (int i = n-1; i >= 1; i--) {
        if (a[i] > v.back()) v.push_back(a[i]);
        else v[lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
    }

    cout << n - max(t, (int)v.size());

    return 0;
}