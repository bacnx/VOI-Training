#include <bits/stdc++.h>
using namespace std;

int s, n, a[102], sumS[102][3003];

void initSumS() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2*s; j++) {
      sumS[i][j] = min(sumS[i-1][j], sumS[i][j-a[i]] + 1);
    }
  }
}

int solve(int s) {
  int res = 2<<29;
  for (int i = 1; i <= s; i++)
    res = min(res, sumS[n][s+i] + sumS[n][i]);
  return res;
}

int main() {
  freopen("change.inp", "r", stdin);
  freopen("change.out", "w", stdout);

  cin >> s >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    // int temp; cin >> temp;
    // a[temp] = 1;
  }

  sort(a+1, a+n+1);
  initSumS();
  // cout << solve(s);
  cout << sumS[n][4];

  return 0;
}