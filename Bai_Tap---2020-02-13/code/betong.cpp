#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+2;
typedef pair<int, int> pii;
int n;
pii a[maxn];
bool avail[maxn];

int main() {
    freopen("betong.inp", "r", stdin);
    freopen("betong.out", "w", stdout);

    cin >> n;;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        avail[i] = true;
    }
    avail[0] = avail[n+1] = true;
    sort(a+1, a+n+1, greater<pii>());

    int res = 0, t = 0;
    for (int i = 1; i <= n; i++) {
        int u = a[i].second, v = a[i+1].second;
        avail[u] = false;
        if (avail[u-1] && avail[u+1]) t++;
        else if (!avail[u-1] && !avail[u+1]) t--;
        
        if (a[i].first == a[i+1].first)
            continue;
        res = max(res, t);
    }
    cout << res;

    return 0;
}