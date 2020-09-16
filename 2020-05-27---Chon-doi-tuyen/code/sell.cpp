#include <bits/stdc++.h>
using namespace std;

const int maxN = 300005;
const double eps = 1e-6;
int n, k;
double a[maxN], sum[maxN];

bool check(double x) {
  sum[0] = 0;
  for (int i = 1; i <= n; i++){
    sum[i] = sum[i-1] + (a[i] - x);
  }

  double sumMin = 1000000;
  for (int i = k; i <= n; i++) {
    sumMin = min(sumMin, sum[i-k]);
    if (sum[i] >= sumMin)
      return true;

  }
  return false;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // t thêm nè
  freopen("sell.inp", "r", stdin);
  freopen("sell.out", "w", stdout);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  double l = 0, r = 1000000, mid, res;
  while (r - l >= eps) {
    mid = (l + r) / 2;
    // cout << fixed << setprecision(7) << mid << '\n';
    if (check(mid)) {
      res = mid;
      l = mid;    // t bỏ + eps;
    } else
      r = mid;
  }

  cout << fixed << setprecision(6) << res;
  // cout << check(6.666667);

  return 0;
}
