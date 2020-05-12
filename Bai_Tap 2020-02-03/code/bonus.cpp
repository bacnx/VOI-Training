#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;
int n, a[maxn];

int main()
{
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1, greater<int>());

    int result = 1, mx = a[1] + 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] + n >= mx) result++;
        else break;
        mx = max(mx, a[i] + i);
    }
    cout << result;

    return 0;
}