#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("transtr.inp", "r", stdin);
  freopen("transtr.out", "w", stdout);

  string nStr, s; cin >> nStr >> s;
  
  int sN = (int)s.size();
  int n = (int)nStr[0] - '0';
  n %= sN;

  for (int i = 1; i < (int)nStr.size(); i++) {
    n = n*10 + nStr[i] - '0';
    n %= sN;
  }

  cout << s.substr(n, sN - n) << s.substr(0, n);
  
  return 0;
}