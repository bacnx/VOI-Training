#include <bits/stdc++.h>
using namespace std;

const int maxnt = 1000004;
const int maxn = 501;
vector<bool> nt(maxnt, true);
vector<int> ntn(maxnt);
int n, m, a[maxn][maxn];

void snt() {
    nt[1] = false;
    for (int i = 2; i <= maxnt; i++)
        if (nt[i] == true) {
            // cout << i << " ";
            // arnt.push_back(i);
            for (int j = 2; j*i <= maxnt; j++)
                nt[j*i] = false;
        }
    
    int a;
    for (int i = 1000003; i > 0; i--) {
        if (nt[i]) a = i;
        ntn[i] = a;
    }
}

int main() 
{
    freopen("bnt.inp", "r", stdin);
    freopen("bnt.out", "w", stdout);

    snt();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] = ntn[a[i][j]] - a[i][j];
        }
    
    int result = INFINITY, t;
    for (int i = 1; i <= n; i++) {
        t = 0;
        for (int j = 1; j <= m; j++)
            t += a[i][j];
        result = min(result, t);
    }
    for (int j = 1; j <= m; j++) {
        t = 0;
        for (int i = 1; i <= n; i++)
            t += a[i][j];
        result = min(result, t);
    }
    cout << result;

    return 0;
}