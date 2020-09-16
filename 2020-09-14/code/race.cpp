#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  freopen("race.inp", "r", stdin);
  freopen("race.out", "w", stdout);

  int x, t1, v1, t2, v2;
  cin >> t1 >> v1 >> t2 >> v2;
  cin >> x;

  int s1 = v1 * t1, s2 = v2 * t2;
  int T1 = (x-1)/s1 * t1*2, T2 = (x-1)/s2 * t2*2;

  if (T1 == T2) {
    if (v1 > v2) cout << "First";
    else if (v1 < v2) cout << "Second";
    else cout << "Draw";
    return 0;
  }
  if (T1 + t1 < T2 + t2) {
    cout << "First";
  } else if (T1 + t1 > T2 + t2) {
    cout << "Second";
  } else {
    cout << "Draw";
  }

  return 0;
}