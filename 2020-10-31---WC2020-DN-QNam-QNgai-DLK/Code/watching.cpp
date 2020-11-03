#include<bits/stdc++.h>
using namespace std;

#define MAX 1000006
#define int long long

int n, m, t, k;
int a[MAX], b[MAX];

int32_t main() {
    freopen("watching.inp", "r", stdin);
    freopen("watching.out", "w", stdout);

    cin >> n >> m >> t >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    a[0] = b[0] = INT_MIN;
    int tChange = 0;
    bool isA = 1;
    int i = 1, j = 1;
    int resA = 0, resB = 0;

    while (true) {
        if (isA) {
            while (i <= n && a[i] <= tChange) i++;

            if (i > n || a[i] >= t) {
                if (a[i-1] + k < t) resA += t - max(a[i-1] + k, tChange);
                break;
            }

            resA += a[i] - max(a[i-1] + k, tChange);
            tChange = a[i];
            isA = false;
        }
        else {
            while (j <= m && b[j] <= tChange) j++;

            if (j > m || b[j] >= t) {
                if (b[j-1] + k < t) resB += t - max(b[j-1] + k, tChange);
                break;
            }

            resB += b[j] - max(b[j-1] + k, tChange);
            tChange = b[j];
            isA = true;
        }
    }
    
    cout << resA << ' ' << resB;

    return 0;
}