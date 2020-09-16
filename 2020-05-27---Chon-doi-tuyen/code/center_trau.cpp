#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;

int n, m, d[maxN], w[maxN];

int solve(int p) {
  int res = 0;
  for (int i = 1; i <= n; i++)
    res += w[i] * abs(d[i] - p);
  return res;
}

int main() {
  freopen("center.inp", "r", stdin);
  freopen("center.ans", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> d[i];
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  
  while (m--) {
    int p; cin >> p;
    cout << solve(p) << '\n';
  }

  return 0;
}