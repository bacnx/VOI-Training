#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
const int maxN = 1e5+1;

int n;
pii a[maxN];
vector<pii> vt;
vector<double> x;

double gd(pii a, pii b) {
  return (double)(b.second - a.second)/(a.first - b.first);
}

int binaryFind(double a) {
  int l = 0, r = x.size()-1, mid;
  int ans = r;
  while (l <= r) {
    mid = (l + r)/2;
    if (a >= x[mid]) {
      ans = mid;
      l = mid + 1;
    } else r = mid - 1;
  }
  return ans;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  freopen("cmin.inp", "r", stdin);
  freopen("cmin.out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].first >> a[i].second;

  sort(a + 1, a + n + 1, greater<pii>());

  for (int i = 1; i <= n; i++) {
    while (!vt.empty() && vt.back().first == a[i].first)
      vt.pop_back();
    while (vt.size() >= 2 && gd(vt[vt.size()-2], vt.back()) > gd(vt.back(), a[i]))
      vt.pop_back();
    vt.push_back(a[i]);
  }

  x.push_back((double)LLONG_MIN);
  for (int i = 1; i < vt.size(); i++) {
    x.push_back(gd(vt[i], vt[i-1]));
  }
  
  int m; cin >> m;
  while (m--) {
    int a; cin >> a;
    int id = binaryFind((double)a);
    cout << vt[id].first * a + vt[id].second << '\n';
  }

  return 0;
}