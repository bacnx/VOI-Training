#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1002;

int m, n, i, j, a, ans = 0;
map<int, int> mp;
int psumA[maxN], psumB[maxN];

int32_t main() {
    freopen("seqpairs.inp", "r", stdin);
    freopen("seqpairs.out", "w", stdout);

    cin >> m >> n;
    for (i = 1; i <= m; i++) {
        scanf("%d", &a);
        psumA[i] = psumA[i-1] + a;
    }
    for (i = 1; i <= n; i++) {
        scanf("%d", &a);
        psumB[i] = psumB[i-1] + a;
    }

    for (i = 1; i <= m; i++)
        for (j = i; j <= m; j++)
            mp[psumA[j] - psumA[i-1]]++;

    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++)
            ans += mp[psumB[j] - psumB[i-1]];
    
    cout << ans;

    return 0;
}