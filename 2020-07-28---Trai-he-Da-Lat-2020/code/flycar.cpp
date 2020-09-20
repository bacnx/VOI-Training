#include <bits/stdc++.h>
using namespace std;

int n, k, a[401];
int d[401];
bool fre[401];

int main() {
  freopen("flycar.inp", "r", stdin);
  freopen("flycar.out", "w", stdout);
  
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[i] = a[i];
    fre[i] = true;
  }

  int nowK = n-1;
  while (nowK > k) {
    int x, minD = INT_MAX;
    for (int i = 1; i < n; i++) {
      if (fre[i] && abs(d[i+1] - d[i]) < minD) {
        minD = abs(d[i+1] - d[i]);
        x = i;
      }
    }
    fre[x] = false;
    d[x] = d[x+1] = max(d[x], d[x+1]);
    nowK--;
  }

  long long res = 0;
  for (int i = 1; i <= n; i++)
    res += (long long)(d[i] - a[i]);
  
  cout << res;

  return 0;
}