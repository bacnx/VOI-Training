#include <bits/stdc++.h>
using namespace std;

int cs(long long a) {
  int result = 0;
  while (a != 0) {
    result ++;
    a /= 10;
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("seqlen.inp", "r", stdin);
  freopen("seqlen.out", "w", stdout);
  
  long long a; cin >> a;
  int n = cs(a);

  long long result = 0, a_ = 0;
  for (int i = 1; i < n; i++) {
    a_ = a_*10+9;
    result += 9 * pow(10, i-1) * i;
  }
  result += (a - a_) * n;

  cout << result;

  return 0;
}