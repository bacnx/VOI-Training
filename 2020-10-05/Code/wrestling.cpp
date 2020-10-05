#include<bits/stdc++.h>
using namespace std;

const int maxN = 5e5+1;

int n, a[maxN], idB[maxN], d[maxN];

int kc(int i) {
    if (i <= idB[a[i]])
        return idB[a[i]] - i;
    else return n + idB[a[i]] - i;
}

int main() {
    freopen("wrestling.inp", "r", stdin);
    freopen("wrestling.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        idB[a] = i;
    }

    for (int i = 1; i <= n; i++) {
        d[kc(i)]++;
    }

    int ansD, ans = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] > ans) {
            ans = d[i];
            ansD = i;
        }
    }
    
    cout << ansD << ' ' << ans;

    return 0;
}