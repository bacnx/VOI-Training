#include<bits/stdc++.h>
using namespace std;

int cnt[10004];
bool fre[10004];
// map<int, int> mp;

int solve(int a) {
  if (a == 0) return 0;
  if (a <= 5) return 100;
  return 100 + a-5;
}

int main() {
  freopen("park.inp", "r", stdin);
  freopen("park.out", "w", stdout);
  
  int n; cin >> n;
  while (n--) {
    int a; cin >> a;
    a -= 10100000;
    // mp[a]++;
    cnt[a]++;
  }

  int ans = 0;
  for (int i = 2010; i <= 9999; i++) {
    ans += solve(cnt[i]);
  }
  // for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
  //   ans += solve(it->second);
  // }
  cout << ans;

  return 0;
}