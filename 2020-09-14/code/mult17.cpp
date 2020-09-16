#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("mult17.inp", "r", stdin);
  freopen("mult17.out", "w", stdout);

  string s; cin >> s;
  string ans = s + "0000";
  s = "0000" + s;
  
  char n = '0';
  int a = 0, b = 0, c = 0;
  for (int i = ans.size()-1; i != 0; i--) {
    a = s[i] - '0';
    b = ans[i] - '0';
    c = n - '0';
    
    if (a + b + c == 3) {
      n = '1';
      ans[i] = '1';
    } else if (a + b + c == 2) {
      n = '1';
      ans[i] = '0';
    } else {
      n = '0';
      ans[i] = a + b + c + '0';
    }
  }
  if (n == '1') ans = "1" + ans;

  cout << ans;

  return 0;
}