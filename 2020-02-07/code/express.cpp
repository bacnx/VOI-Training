#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[100005], psum[100005];

int32_t main()
{
    freopen("express.inp", "r", stdin);
    freopen("express.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    psum[0] = 0;
    for (int i = 1; i <= n; i++)
        psum[i] = psum[i-1] + a[i];
    
    int result = 0, t;
    for (int i = 2; i < n; i++)
        for (int j = i+1; j <= n; j++) {
            if (j == i+1) t = psum[i-2] + a[i-1]*a[i]*a[i+1] + psum[n] - psum[j];
            else t = psum[i-2] + a[i-1]*a[i] + psum[j-2]-psum[i] + a[j-1]*a[j] + psum[n] - psum[j];
            result = max(result, t);
        }
    cout << result;

    return 0;
}