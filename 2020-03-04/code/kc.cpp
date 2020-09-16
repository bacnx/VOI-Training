#include <bits/stdc++.h>
using namespace std;

int n, a[100005];
// pair<int, int> a[maxn];

int main() 
{
    freopen("kc.inp", "r", stdin);
    freopen("kc.out", "w", stdout);

    cin >> n;
    int t, p;
    for (int i = 1; i <= n; i++) {
        cin >> t >> p;
        t += 32000, p += 32000;
        if (t > p) swap(t, p);
        a[t+1]++, a[p+1]--;
    }

    int res = 0, c = 0;
    for (int i = 1; i <= 64004; i++) {
        a[i] += a[i-1];
        // cout << a[i] << endl;
        if (a[i] > 0) c++;
        else c = 0;
        res = max(res, c);
    }
    cout << res;

    return 0;
}