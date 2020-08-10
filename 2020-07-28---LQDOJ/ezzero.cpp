#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, x; cin >> a >> x;
  long long d = (long long)pow(10, x);
  
  long long res;
  if (a == 0) res = d;
  else if (a%d == 0) res = 0;
  else res = d - a%d;
  cout << res;

  return 0;
}