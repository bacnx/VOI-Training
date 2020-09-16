#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int n, m, a[maxN];

int searchBinary(int x, int l, int r) {
  int mid, res = -1;
  while (l <= r) {
    mid = (l + r) / 2;
    // cerr << l << ' ' << r << ' ' << mid << '\n';
    if (a[mid] <= x) {
      res = mid;
      l = mid + 1;
    } else r = mid - 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("fm.inp", "r", stdin);
  freopen("fm.out", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  sort(a + 1, a + n + 1);

  int result = 0;
  for (int i = 1; i <= n; i++) {
    int i_ = searchBinary(m - a[i], 1, n);
    if (i_ == -1 || i_ <= i) break;
    result += i_ - i;
    // cerr << i_ << " " << i << ' ' << result << '\n';
  }
  
  cout << result;

  return 0;
}