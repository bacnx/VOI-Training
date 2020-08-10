#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  string res = "@";
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] != res[i % (int)res.size()])
      res = s.substr(0, i+1);
  }
  cout << res;

  return 0;
}