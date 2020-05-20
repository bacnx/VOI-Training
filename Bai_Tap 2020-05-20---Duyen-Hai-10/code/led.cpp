#include <bits/stdc++.h>
using namespace std;

#define int long long

int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[10] = {1, 6, 1, 2, 2, 3, 1, 4, 0, 1};
int b[10] = {1, 5, 1, 2, 2, 3, 1, 2, 0, 0};

void case1() {
  string str;
  cin >> str;
  
  int res = 0;
  for (int i = 0; i < (int)str.size(); i++) {
    res += c[(int)str[i]-48];
  }
  cout << res;
}

void case2() {
  string str;
  cin >> str;

  int res = 0, s = 1;
  for (int i = (int)str.size()-1; i >= 0; i--) {
    int num = (int)str[i] - 48;
    res += s * b[num];
    s *= a[num] + 1;
  }
  cout << res;
}

int32_t main() {
  freopen("led.inp", "r", stdin);
  freopen("led.out", "w", stdout);

  int v;
  cin >> v;

  if (v == 1) {
    case1();
  } else {
    case2();
  }

  return 0;
}