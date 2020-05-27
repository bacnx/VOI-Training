#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
struct donhang { int a, b, c; };
bool cmp(const donhang &a, const donhang &b) { return a.a < b.a; }
int n, s[maxn];
donhang a[maxn];

int main()
{
    freopen("dq.inp", "r", stdin);
    freopen("dq.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b >> a[i].c;
    sort(a+1, a+n+1, cmp);

    int res = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j < a[i].a)
            s[j] = max(s[j], s[(j++)-1]);
        s[j] = max(s[j], s[j-1]);
        s[a[i].b] = max(s[a[i].b], s[a[i].a] + a[i].c);
        res = max(res, s[a[i].b]);
    }
    cout << res;

    return 0;
}