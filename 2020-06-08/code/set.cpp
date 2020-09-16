#include <bits/stdc++.h>
using namespace std;

void solve() {
  int k, a, b; cin >> k >> a >> b;\
  int kc = b - a;
  while (__gcd(k, kc) != 1)
    kc /= __gcd(k, kc);
    
  int m; cin >> m;
  while (m--) {
    int p, q; cin >> p >> q;

    if (k == 1 && p < a) {
      cout << "NO\n";
      continue;
    }
    if (q - p > 0 && (q - p) % kc == 0)
      cout << "YES\n";
    else 
      cout << "NO\n";
  }
}

int main() {
  freopen("set.inp", "r", stdin);
  freopen("set.out", "w", stdout);

  int t; cin >> t;
  while (t--)
    solve();

  return 0;
}