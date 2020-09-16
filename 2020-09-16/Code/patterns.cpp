#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("patterns.inp", "r", stdin);
  freopen("patterns.out", "w", stdout);

  string a, b; cin >> a >> b;
  int ans = 1;
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] < b[i]) swap(a[i], b[i]);
    if (b[i] == '?' || a[i] == '?') {
      if (a[i] == '?' && b[i] == '?') ans *= 10;
      else if (a[i] > '?') ans *= 4;
    } else if (a[i] > '?') {
      if (b[i] > '?') ans *= max(0, b[i] - a[i] + 4);
      else if (b[i] - '0' + 'a'-1 < a[i] || b[i] - '0' + 'a'-1 > b[i] + 3) ans = 0;
    } else if (a[i] != b[i]) ans = 0;
  }
  
  cout << ans;

  return 0;
}