#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int n;
long long a[maxN], b[maxN];

int main() {
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+n, greater<long long>());

    int i = 0, j = 0;
    long long ans = LLONG_MAX;
    while (max(i, j) < n) {
        ans = min(ans, abs(a[i] + b[j]));
        if (a[i] + b[j] > 0) j++;
        else if (a[i] + b[j] < 0) i++;
        else break;
    }

    cout << ans;

    return 0;
}