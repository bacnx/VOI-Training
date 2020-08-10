#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  long long res = 1;
  int mx = 0;
  while (n--) {
    int a; cin >> a;
    res += (long long)a;
    mx = max(mx, a);
  }
  res -= min(k, mx);
  cout << res;

  return 0;
}