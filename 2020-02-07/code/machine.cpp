#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6+1;
int n, s[maxn], t[maxn];

int main()
{
    freopen("machine.inp", "r", stdin);
    freopen("machine.out", "w", stdout);

    cin >> n;
    int a, b, be = maxn, en = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a >> b;
        s[a] = max(s[a], b-a);
        t[b] = max(t[b], b-a);
        be = min(be, a), en = max(en, b);
    }

    int result = 0, mx = -maxn;
    for (int i = be; i <= en; i++) {
        if (s[i]) result = max(result, mx + s[i]);
        if (t[i]) mx = max(mx, t[i]);
    }
    cout << result;

    return 0;
}