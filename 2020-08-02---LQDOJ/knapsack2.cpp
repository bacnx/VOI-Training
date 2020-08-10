#include <bits/stdc++.h>
using namespace std;

const int maxN = 101;
int n, m, W, w[maxN], v[maxN];

int main() {
  cin >> n >> W; m = 0;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    m += v[i];
  }
  
  int result = 0;
  vector<vector<int> > L(n+1, vector<int>(m+1, 1e9+2));
  for (int i = 1; i <= n; i++) {
    L[i-1][0] = 0;
    for (int j = 1; j <= m; j++) {
      if (j >= v[i])
        L[i][j] = min(L[i-1][j], L[i-1][j-v[i]] + w[i]);
      else
        L[i][j] = L[i-1][j];
      if (L[i][j] <= W) result = max(result, j);
      // cout << L[i][j] << ' ';
    }
    // cout << '\n';
  }
  cout << result;

  return 0;
}