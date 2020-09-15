#include<bits/stdc++.h>
using namespace std;

int g[200];
void initG() {
  g['H'] = 1;
  g['O'] = 16;
  g['N'] = 14;
  g['C'] = 12;
}

int main() {
  freopen("molecular.inp", "r", stdin);
  freopen("molecular.out", "w", stdout);

  initG();

  string str; cin >> str;
  
  int ans = 0;
  for (int i = 0; i < (int)str.size(); i++) {
    int cnt = 0, G = g[str[i]];
    while (i != (int)str.size()-1 && str[i+1] <= '9') {
      i++;
      cnt = cnt*10 + str[i] - '0';
    }
    if (str[i] > '9') cnt = 1;
    ans += G * cnt;
  }

  cout << ans;

  return 0;
}