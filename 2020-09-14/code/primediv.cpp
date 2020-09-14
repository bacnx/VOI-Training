#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("primediv.inp", "r", stdin);
  freopen("primediv.out", "w", stdout);

  long long n; cin >> n;
  long long nTemp = n;

  for (int i = 2; i <= (int)sqrt(n); i++) {
    if (nTemp % i == 0) {
      cout << i << ' ';
      while (nTemp % i == 0)
        nTemp /= i;
      if (nTemp == 1) break;
    }
  }
  if (nTemp != 1) cout << nTemp;
  
  return 0;
}