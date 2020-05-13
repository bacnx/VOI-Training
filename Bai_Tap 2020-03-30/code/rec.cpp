#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("rec.inp", "r", stdin);
  freopen("rec.out", "w", stdout);

  int n, m, p;
  cin >> n >> m >> p;
  cout << n*(n+1)/2*m*(m+1)/2;

  return 0;
}