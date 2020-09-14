#include <bits/stdc++.h>
using namespace std;

// map<int, int> mp;
bool cnt[10000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  freopen("demso.inp", "r", stdin);
  freopen("demso.out", "w", stdout);

  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int a; cin >> a;
    // if (mp.find(a) != mp.end())
    if (cnt[a])
      ans++;
    // mp[a]++;
    cnt[a] = true;
  }

  cout << ans;

  return 0;
}