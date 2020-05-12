#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

int main()
{
    freopen("chiaday.inp", "r", stdin);
    freopen("chiaday.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);

    int t1 = 0, t2 = 0, i = 1;
    for (; i <= (n+1)/2; i++)
        t2 += a[i];
    for (; i <= n; i++)
        t1 += a[i];
    
    cout << t1 - t2;

    return 0;
}