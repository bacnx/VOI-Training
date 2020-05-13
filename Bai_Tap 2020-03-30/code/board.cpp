#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m, res;
  const long long mod = 1e9+7;
  cin >> n >> m;
  
  res = (((n * (n-1) / 2)%mod) * ((m * (m-1) / 2)%mod) + 1) % mod;
  cout << res;

  return 0;
}