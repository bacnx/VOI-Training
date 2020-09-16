#include <bits/stdc++.h>
using namespace std;

int s, n, a[102], sumS[102][20004];

void initSumS() {
  for (int i = 1; i <= 2*s; i++)
    sumS[0][i] = 99999999;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2*s; j++) {
      if (j < a[i])
        sumS[i][j] = sumS[i-1][j];
      else
        sumS[i][j] = min(sumS[i-1][j], sumS[i][j-a[i]] + 1);
    }
  }
}

int solve(int s) {
  int res = 99999999;
  for (int i = 0; i < s; i++)
    res = min(res, sumS[n][s+i] + sumS[n][i]);
  return res;
}

int main() {
  freopen("change.inp", "r", stdin);
  freopen("change.out", "w", stdout);

  cin >> s >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  sort(a+1, a+n+1);
  initSumS();
  cout << solve(s);

  return 0;
}