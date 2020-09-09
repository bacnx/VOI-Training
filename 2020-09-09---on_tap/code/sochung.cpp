#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main() {
  freopen("sochung.inp", "r", stdin);
  freopen("sochung.out", "w", stdout);

  int n, m; cin >> n >> m;
  
  for (int i = 1; i <= n; i++) {
    int a; cin >> a;
    mp[a]++;
  }

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int a; cin >> a;
    if (mp[a] != 0) {
      ans++;
      mp[a]--;
    }
  }

  cout << ans;

  return 0;
}