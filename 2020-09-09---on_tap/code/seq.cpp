#include <bits/stdc++.h>
using namespace std;

int n, k, a[100005];

int main() {
  freopen("seq.inp", "r", stdin);
  freopen("seq.out", "w", stdout);

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  sort(a+1, a+n+1);

  long long ans = 0;
  for (int i = 1; i <= n-k; i++)
    ans += a[i];
  
  cout << ans;
  
  return 0;
}