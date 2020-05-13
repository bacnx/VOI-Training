#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("coin.inp", "r", stdin);
  freopen("coin.out", "w", stdout);

  int n, k;
  string s;
  cin >> n >> k >> s;
  int res = 0;

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == 'O') {
        sum++;
      } else {
        sum--;
      }
      if (sum == k) {
        res = max(res, j-i+1);
      }
    }
  }

  cout << res;

  return 0;
}