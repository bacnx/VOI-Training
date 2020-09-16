#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k, a[10004], cnt[43];

int32_t main() {
  freopen("power.inp", "r", stdin);
  freopen("power.out", "w", stdout);

  cin >> n >> k;
  while (n--) {
    int temp; cin >> temp;
    for (int i = 2; temp > 1; i++) {
      int c = 0;
      while (temp % i == 0) {
        c++;
        temp /= i;
      }
      cnt[i] = max(cnt[i], c);
    }
  }

  int res = 1, cntMax = 0;
  for (int i = 2; i < 43; i++) {
    if (cnt[i])
      res *= pow(i, (int)(cnt[i] + k-1)/k);
  }

  cout << res;

  return 0;
}