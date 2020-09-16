#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7, maxN = 5e5+9;
int n, a[maxN];
int sumAi[maxN], sumAll = 0;
int res = 0;

int32_t main() {
  freopen("subseq.inp", "r", stdin);
  freopen("subseq.out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  for (int i = 1; i <= n; i++) {
    int t = (1 + sumAll+MOD - sumAi[a[i]])%MOD;
    sumAi[a[i]] = (sumAi[a[i]] + t) % MOD;
    sumAll = (sumAll + t) % MOD;
    res = (res + t) % MOD;
  }

  cout << res;

  return 0;
}