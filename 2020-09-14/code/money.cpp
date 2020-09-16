#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("money.inp", "r", stdin);
  freopen("money.out", "w", stdout);

  int g, s, k; cin >> g >> s >> k;
  int n; cin >> n;
  int p = 0, q = 0, r = 0;
  while (n--) {
    int a, b, c; cin >> a >> b >> c;
    p += a, q += b, r += c;
  }

  k -= r;
  if (k < 0) {
    s -= (-(k-28))/29;
    k += 29 * (((-k)+28)/29);
  }
  s -= q;
  if (s < 0) {
    g -= ((-s)+16)/17;
    s += 17 * (((-s)+16)/17);
  }
  g -= p;
  if (g < 0) {
    cout << "-1";
    return 0;
  }

  cout << g << ' ' << s << ' ' << k;

  return 0;
}