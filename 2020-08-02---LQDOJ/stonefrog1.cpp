#include <bits/stdc++.h>
using namespace std;

int n, a[100005], rs[100005];

int d(int x, int y) {
  return abs(a[x] - a[y]);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  rs[1] = 0, rs[2] = abs(a[2] - a[1]);
  for (int i = 3; i <= n; i++)
    rs[i] = min(rs[i-2] + d(i, i-2), rs[i-1] + d(i, i-1));
  
  cout << rs[n];

  return 0;
}