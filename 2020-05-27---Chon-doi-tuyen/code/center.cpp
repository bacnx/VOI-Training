#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;

const int maxN = 1e5+5;
int n, m;
pii a[maxN];
int sumDW[maxN], sumW[maxN];

int searchBinary(int x, int l, int r) {
  int mid, res;
  while (l <= r) {
    mid = (l + r) / 2;
    if (x >= a[mid].first) {
      res = mid;
      l = mid + 1;
    } else 
      r = mid - 1;
  }
  return res;
}

int solve(int p) {
  if (p < a[1].first)
    return sumDW[n] - sumW[n]*p;
  if (p > a[n].first)
    return sumW[n]*p - sumDW[n];

  int x = searchBinary(p, 1, n);
  return sumW[x]*p - sumDW[x] + (sumDW[n]-sumDW[x]) - (sumW[n]-sumW[x])*p;
}

int32_t main() {
  freopen("center.inp", "r", stdin);
  freopen("center.out", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i].first;
  for (int i = 1; i <= n; i++)
    cin >> a[i].second;

  sort(a+1, a+n+1);
  for (int i = 1; i <= n; i++) {
    sumDW[i] = sumDW[i-1] + a[i].first * a[i].second;
    sumW[i] = sumW[i-1] + a[i].second;
  }

  while (m--) {
    int p; cin >> p;
    cout << solve(p) << '\n';
  }

  return 0;
}