#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("seqlen.inp", "r", stdin);
  freopen("seqlen.out", "w", stdout);

  long long n; cin >> n;
  long long ans = 0;
  int cnt = 0;

  while (true) {
    cnt++;
    if (pow(10, cnt) > n) break;
    ans += 9 * pow(10, cnt-1) * cnt;
  }
  ans += (n - pow(10, cnt-1) + 1) * cnt;

  cout << ans;

  return 0;
}