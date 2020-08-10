#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a; cin >> a;
  a /= 2;
  long long res = (a/2) * ((a+1)/2);
  cout << res;

  return 0;
}