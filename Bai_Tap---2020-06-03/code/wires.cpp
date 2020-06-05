#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
const int maxN = 1003;

int n;
pii a[maxN];
int t[maxN];

int kc(pii a, pii b) {
  int x = abs(a.first - b.first), y = abs(a.second - b.second);
  return x + y - __gcd(x, y);
}

void solve() {
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  vector<int> d(n+1, INT32_MAX);
  vector<bool> avail(n+1, true);
  pq.push(pii(0, 1));
  d[1] = 0;
  int res = 0;
  
  while(!pq.empty()) {
    int u = pq.top().second; pq.pop();
    if (!avail[u]) continue;
    avail[u] = false;
    for (int v = 1; v <= n; v++) {
      if (!avail[v]) continue;
      if (d[v] > kc(a[u], a[v])) {
        d[v] = kc(a[u], a[v]);
        pq.push(pii(d[v], v));
        t[v] = u;
      }
    }
    res += d[u];
  }
  
  cout << res << '\n';
  for (int i = 2; i <= n; i++)
    cout << i << ' ' << t[i] << '\n';
}

int32_t main() {
  freopen("wires.inp", "r", stdin);
  freopen("wires.out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].first >> a[i].second;
  
  solve();

  return 0;
}