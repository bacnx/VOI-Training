#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("sell.inp", "r", stdin);
  freopen("sell.ans", "w", stdout);

  int n, k; cin >> n >> k;
  int a[300005];
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  double res = 0;
  for (int i = 1; i <= n; i++) {
    int temp = 0;
    for (int j = i; j < i+k; j++)
      temp += a[j];
    res = max(res, (double)temp/k);
    for (int j = i+k; j <= n; j++) {
      temp += a[j];
      res = max(res, (double)temp/(j-i+1));
    }
  }

  // cout << fixed << setprecision(6) << res;
  cout << (int)(res * 1000000) / 1000000 << '.' << (int)(res * 1000000) % 1000000;

  return 0;
}