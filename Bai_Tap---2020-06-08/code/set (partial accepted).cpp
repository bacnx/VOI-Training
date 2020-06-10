#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int k, a, b;
bool e[51][51];
vector<pii> v;

void dfs(pii u) {
  int x = u.first, y = u.second;
  if (e[x][y]) return ;
  e[x][y] = true;
  v.push_back(u);

  if (u.second < 50) 
    dfs(pii(x+1, y+1));
  if (x % k == 0 && y % k == 0)
    dfs(pii(x/k, y/k));
  for (int i = 1; i <= 50; i++) {
    if (e[y][i])
      dfs(pii(x, i));
    if (e[i][x])
      dfs(pii(i, y));
  }
}

void init() {
  for (int i = 1; i <= 50; i++)
    for (int j = 1; j <= 50; j++)
      e[i][j] = false;
  while (!v.empty())
    v.pop_back();
}

void solve() {
  init();
  cin >> k >> a >> b;
  dfs(pii(a, b));

  int m; cin >> m;
  while (m--) {
    int x, y; cin >> x >> y;
    if (e[x][y])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main() {
  freopen("set.inp", "r", stdin);
  freopen("set.out", "w", stdout);

  int t; cin >> t;
  while (t--)
    solve();

  return 0;
}