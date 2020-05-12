#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[200005];

int main() {
  cin >> m >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a+1, a+n+1);

  int res = 0;
  int begin = a[1], end = begin + k - 1, beforeEnd = begin - 1;

  for (int i = 1; i <= n; i++) {
    if (a[i] > end) {
      res += k;
      beforeEnd = end;
      begin = a[i];
      end = begin + k - 1;
    }
  }
  res += min(k, a[n] - beforeEnd);

  cout << res;

  return 0;
}