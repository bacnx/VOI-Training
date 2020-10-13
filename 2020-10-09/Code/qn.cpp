#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

int main() {
    freopen("qn.inp", "r", stdin);
    freopen("qn.out", "w", stdout);

    cin >> n >> k;

    v.push_back(0); v.push_back(1);

    for (int i = 1; i < n; i++) {
        for (int j = v.size()-1; j >= 0; j--) {
            v.push_back(v[j] | (1<<i));
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] != k) continue;

        for (int j = i+1; j < v.size(); j++)
            cout << v[j] << ' ';
        for (int j = 0; j < i; j++)
            cout << v[j] << ' ';
    }

    return 0;
}