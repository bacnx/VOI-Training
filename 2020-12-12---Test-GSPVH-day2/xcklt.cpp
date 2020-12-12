#include<bits/stdc++.h>
using namespace std;

const int MAX = 502;

string a, b, c;

void solveSub1() {
    if (c == a || c == b) {
        cout << "TRETRAU";
        return ;
    }
    if (a == b) {
        cout << "1\n" << a;
    } else {
        cout << "2\n" << a << b;
    }
}

int f[MAX][MAX];

void solve() {
    int n = (int)a.size();
    int m = (int)b.size();
    a = " " + a;
    b = " " + b;

    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int j = 1; j <= m; j++) f[0][j] = j;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1);
        if (a[i] == b[j]) {
            f[i][j] = min(f[i][j], f[i-1][j-1] + 1);
        } else {
            f[i][j] = min(f[i][j], f[i-1][j-1] + 2);
        }
    }
    cout << f[n][m] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("xcklt.inp", "r", stdin);
    freopen("xcklt.out", "w", stdout);

    cin >> a >> b >> c;

    if ((int)a.size() == 1 && (int)b.size() == 1 && (int)c.size() == 1)
        solveSub1();
    else solve();

    return 0;
}