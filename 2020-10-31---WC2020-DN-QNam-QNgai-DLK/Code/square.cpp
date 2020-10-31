#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("square.inp", "r", stdin);
    freopen("square.out", "w", stdout);

    long long k; cin >> k;

    if (k == 0) cout << '0';
    else if ((k & 1) == 0) cout << "none";
    else if (k > 0) cout << (k-1)/2 + 1;
    // else

    return 0;
}