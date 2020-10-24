#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("quyhoachdong.inp", "r", stdin);
    freopen("quyhoachdong.out", "w", stdout);

    int a, b, c, m;
    while (cin >> a >> b >> c >> m) {
        if (m < 3 || a + b + c < m || min(a, min(b, c)) == 0)
            cout << "Yes ";
        else cout << "No ";
    }

    return 0;
}