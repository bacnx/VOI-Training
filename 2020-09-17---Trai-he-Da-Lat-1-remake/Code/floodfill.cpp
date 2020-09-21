#include <bits/stdc++.h>
using namespace std;

int n, res = 0;
stack<int> sta;
vector<bool> isSta(5001, false);

void Pop(int x) {
  while (sta.top() != x) {
    isSta[sta.top()] = false;
    sta.pop();
    res++;
  }
}

int main() {
  freopen("floodfill.inp", "r", stdin);
  freopen("floodfill.out", "w", stdout);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    int c; cin >> c;
    
    if (!isSta[c]) {
      sta.push(c);
      isSta[c] = true;
      continue;
    }
    if (c != sta.top()) {
      if (isSta[c])
        Pop(c);
      else {
        sta.push(c);
        isSta[c] = true;
      }
    }
  }
  
  res += (int)sta.size() - 1;
  cout << res;

  return 0;
}