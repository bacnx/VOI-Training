#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, K, h[401];
// vector<vector<int> >f(401, vector<int>(401, INT_MAX));
int f[401][401];
int s[401], mxS[401];
int mxH[401][401];

void init() {
  for (int i = 1; i <= n; i++) {
    mxH[i][i] = h[i];
    for (int j = i+1; j <= n; j++)
      mxH[i][j] = max(h[j], mxH[i][j-1]);
  }
}

int32_t main() {
  freopen("flycar.inp", "r", stdin);
  freopen("flycar.out", "w", stdout);

  cin >> n >> K;
  for (int i = 1; i <= n; i++)
    cin >> h[i];

  init();
  s[n] = mxS[n] = h[n];
  for (int i = n-1; i > 0; i--) {
    mxS[i] = max(mxS[i+1], h[i]);
    s[i] = s[i+1] + h[i];
  }

  for (int k = 0; k <= K; k++)
    f[0][k] = 0;
  int mxTemp = 0;
  for (int i = 1; i < n; i++) {
    mxTemp = max(mxTemp, h[i]);
    f[i][0] = mxTemp*i - (s[1] - s[i+1]);
  }

  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= K; k++) {
      f[i][k] = INT_MAX;
      for (int j = 0; j < i; j++) {
        f[i][k] = min(f[i][k], f[j][k-1] + mxH[j+1][i]*(i-j) - (s[j+1] - s[i+1]));
      }
    }
  }
  
  cout << f[n][K];

  return 0;
}