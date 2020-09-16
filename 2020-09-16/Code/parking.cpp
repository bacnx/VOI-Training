#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("parking.inp", "r", stdin);
  freopen("parking.out", "w", stdout);

  int n, m; cin >> n >> m;
  cout << (long long)((n + 1)/2) * ((m + 1)/2);

  return 0;
}