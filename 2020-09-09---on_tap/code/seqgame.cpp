#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("seqgame.inp", "r", stdin);
  freopen("seqgame.out", "w", stdout);

  int n; cin >> n;

  int mxA = INT_MIN, mnA = INT_MAX;
  for (int i = 1; i <= n; i++) {
    int a; cin >> a;
    mxA = max(mxA, a);
    mnA = min(mnA, a);
  }

  int mxB = INT_MIN, mnB = INT_MAX;
  for (int i = 1; i <= n; i++) {
    int a; cin >> a;
    mxB = max(mxB, a);
    mnB = min(mnB, a);
  }

  int ans = max(mxA + mxB, (mnA + mnB)*(-1));
  cout << ans;

  return 0;
}