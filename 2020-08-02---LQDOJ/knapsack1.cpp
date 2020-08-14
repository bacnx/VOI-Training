#include <bits/stdc++.h>
using namespace std;

int n, W, w[101], v[101];
long long l[101][100005];

int main() {
  cin >> n >> W;
  for (int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      l[i][j] = max(l[i-1][j], l[i][j-1]);
      if (j >= w[i])
        l[i][j] = max(l[i][j], l[i-1][j-w[i]] + (long long)v[i]);
    }
  }

  cout << l[n][W];

  return 0;
}