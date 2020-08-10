#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n; cin >> n;
  long long res = 0;
  for (int i = 1; i < (n+2)/3; i++) {
    res += (n-i + 1)/2 - 1 - i;
  }
  cout << res;

  return 0;
}