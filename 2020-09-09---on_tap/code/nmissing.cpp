#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  sort(a+1, a+n+1);

  int ans = 2;
  for (int i = 1; i <= n; i++)
    if (a[i] >= ans) ans += 2;
  
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  freopen("nmissing.inp", "r", stdin);
  freopen("nmissing.out", "w", stdout);

  int t; cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }
  
  return 0;
}