#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("dientich.inp", "r", stdin);
  freopen("dientich.out", "w", stdout);
  
  long long x1, x2, y1, y2, u1, u2, v1, v2;
  cin >> x1 >> y2 >> x2 >> y1;
  cin >> u1 >> v2 >> u2 >> v1;

  long long a, b, c, d;
  a = max(x1, u1), b = max(y1, v1);
  c = min(x2, u2), d = min(y2, v2);

  if (a > c || b > d) {
    cout << '0';
    return 0;
  }

  long long ans = (c - a) * (d - b);
  cout << ans;

  return 0;
}