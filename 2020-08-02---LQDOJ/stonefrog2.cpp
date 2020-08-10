#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int maxN = 1e5+1;
int n, k, a[maxN];
// priority_queue<pii, vector<pii>, greater<pii> > pq;
int dMn[maxN];

int d(int i, int j) {
  return abs(a[i] - a[j]);
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  // pq.push(pii(0, 1));
  // int res = 0;
  for (int i = 2; i <= n; i++) {
    // while (pq.top().second < i-k)
    //   pq.pop();
    // res = pq.top().first + d(i, pq.top().second);
    // pq.push(pii(res, i));
    dMn[i] = INT32_MAX;
    for (int j = i-1; j >= max(1, i-k); j--)
      dMn[i] = min(dMn[i], dMn[j] + d(i, j));
  }
  // cout << res;
  cout << dMn[n];

  return 0;
}