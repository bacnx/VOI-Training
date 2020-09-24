#include<bits/stdc++.h>
using namespace std;

#define int long long
const int nMax = 1e5+1;

int n, a[nMax], b[nMax];

int32_t main() {
  freopen("cmax.inp", "r", stdin);
  freopen("cmax.ans", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  
  int m; cin >> m;
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    int ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, a[i]*x + b[i]);
    }
    cout << ans << '\n';
  }

  return 0;
}