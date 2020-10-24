#include<bits/stdc++.h>
using namespace std;

vector<bool> isPrime(100005, true);

bool isPri(int x) {
    if (x < 2) return false;
    int n = (int)sqrt(x);
    for (int i = 2; i <= n; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    freopen("triprime.inp", "r", stdin);
    freopen("triprime.out", "w", stdout);

    int a; cin >> a;
    
    int n = (int)sqrt(a), cnt = 0;
    int s;

    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;

        if (a % i == 0) {
            a /= i;
            cnt++;
            s = i;
            if (cnt == 2) break;
        }
        for (int j = 2; j*i <= n; j++) isPrime[j*i] = false;
    }

    if (cnt == 2 && a > s && isPri(a)) cout << "YES";
    else cout << "NO";

    return 0;
}