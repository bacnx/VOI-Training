#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("gcdlcm.inp", "r", stdin);
    freopen("gcdlcm.out", "w", stdout);

    srand(time(nullptr));
    string ans[] = { "Y", "N" };

    int O, t; cin >> O >> t;
    while (t--) {
        int r = (int)rand() % 2;
        cout << ans[r];
    }

    return 0;
}