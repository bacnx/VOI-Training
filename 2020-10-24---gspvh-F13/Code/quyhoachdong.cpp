#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("quyhoachdong.inp", "r", stdin);
    freopen("quyhoachdong.out", "w", stdout);

    int a[4];
    while (true) {
        a[0] = -1;
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        if (a[0] == -1) break;  
        sort(a, a+4);
        if (a[0] > 0 && a[0] + a[1] + a[2] >= a[3]) cout << "No ";
        else cout << "Yes ";
    }

    return 0;
}