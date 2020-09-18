#include<bits/stdc++.h>
using namespace std;

int n, K, h[401];
vector<vector<int> >f(401, vector<int>(401, INT_MAX));
int s[401], mxS[401];

int main() {
  // freopen

  cin >> n >> K;
  for (int i = 1; i <= n; i++)
    cin >> h[i];
  
  s[n] = mxS[n] = h[n];
  for (int i = n-1; i > 0; i--) {
    mxS[i] = max(mxS[i+1], h[i]);
    s[i] = s[i+1] + h[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < K; k++) {
      for (int j = 1; j < n; j++)
        f[i][k] = min(f[i][k], f[j][k-1] + mxS[j+1] * (n-j) - s[j+1]);
    }
  }

  cout << f[n][K];

  return 0;
}