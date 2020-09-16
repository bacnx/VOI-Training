#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;
int n, m;

int maxCount(vector<int> index) {
  int res = 0;
  int i, j;
  for (i = 0, j = 0; max(i, j) < (int)index.size()-1; i++) {
    while(j < (int)index.size()-1 && (index[j+1]-index[i]) - (j+1 - i) <= m)
      j++;
    int t = (index[j] - index[i] + 1) + (m - (index[j] - index[i] - (j - i)));
    res = max(res, t);
  }

  return res;
}

void solve() {
  vector<int> indexType[300];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    char temp; cin >> temp;
    indexType[temp].push_back(i);
  }
  
  int res = 0;
  for (int i = 0; i < 26; i++) {
    res = max(res, maxCount(indexType[(char)'A'+i]));
    res = max(res, maxCount(indexType[(char)'a'+i]));
  }

  cout << min(res, n) << '\n';
}

int main() {
  freopen("chocola.inp", "r", stdin);
  freopen("chocola.out", "w", stdout);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}