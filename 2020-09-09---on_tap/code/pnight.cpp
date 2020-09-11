#include <bits/stdc++.h>
using namespace std;

int a[10004], b[10004];

bool solve() {
  int n, m; cin >> n >> m; 
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> b[i];
  if (n > m) return false;

  sort(a+1, a+n+1);
  sort(b+1, b+m+1);

  for (int i = 1; i <= n; i++) {
    if (a[i] <= b[i])
      return false;
  }
  return true;
}

int main() {
  freopen("pnight.inp", "r", stdin);
  freopen("pnight.out", "w", stdout);

  int t; cin >> t;
  while (t--) {
    bool ans = solve();
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  
  return 0;
}