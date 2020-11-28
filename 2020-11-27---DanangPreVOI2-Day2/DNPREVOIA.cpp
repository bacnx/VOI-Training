#include<bits/stdc++.h>
using namespace std;

int n, a[400005];
bool selected[400005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("A.inp", "r", stdin); 

    int t; cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        selected[a[i]] = true;
    }

    int id = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) cout << a[i] << ' ';
        else {
            while (selected[id]) id++;
            cout << id << ' ';
            id++;
        }
    }

    return 0;
}