#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxN = 300005;
int n, k, a[maxN];
int s[maxN];

double average(int l, int r) {
  return (double)(s[r] - s[l-1]) / (double)(r-l+1);
}

int32_t main() {
  freopen("sell.inp", "r", stdin);
  freopen("sell.out", "w", stdout);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  int valueMax = 0;
  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    s[i] = s[i-1] + a[i];
    valueMax = max(valueMax, a[i]);
  }

  double res = 0;
  int l, r;
  for (int i = 1; i+k-1 <= n; i++) {
    if (res < average(i, i+k-1)) {
      res = average(i, i+k-1);
      l = i, r = i+k-1;
    }
  }

  double resLeft = res, resRight = res;
  for (int i = l; i > 0; i--) {
    // res = max(res, average(i, r));
    if (res < average(i, r)) {
      res = average(i, r);
      l = i;
    }
  }
  for (int i = r; i <= n; i++) {
    // res = max(res, average(l, j));
    if (res < average(l, i)) {
      res = average(l, i);
      r = i;
    }
  }
  // cout << (int)(res * 1000000);
  cout << fixed << setprecision(6) << res;
  // printf("%f", res);
  // cout << (int)(res * 1000000) / 1000000 << '.' << (int)(res * 1000000) % 1000000;

  return 0;
}