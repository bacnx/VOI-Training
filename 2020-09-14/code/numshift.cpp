#include<bits/stdc++.h>
using namespace std;

#define int long long

string numToStr(int n) {
  string ans = "";
  while (n != 0) {
    ans = (char)(n%2) + ans;
    n /= 2;
  }
  return ans;
}

int strToNum(string str) {
  int ans = 0;
  for (int i = 0; i < (int)str.size(); i++)
    ans = ans * 2 + (int)(str[i]);
  return ans;
}

int32_t main() {
  freopen("numshift.inp", "r", stdin);
  freopen("numshift.out", "w", stdout);

  int n; cin >> n;
  
  int ans = n;
  string str = numToStr(n);
  for (int i = 1; i < (int)str.size(); i++) {
    string strTemp = str.substr(i, (int)str.size() - i) + str.substr(0, i);
    ans = max(ans, strToNum(strTemp));
  }

  cout << ans;

  return 0;
}