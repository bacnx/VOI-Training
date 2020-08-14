#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int a0, b0, c0; cin >> a0 >> b0 >> c0; n--;
  int a, b, c;
  while (n--) {
    cin >> a >> b >> c;
    a += max(b0, c0);
    b += max(a0, c0);
    c += max(a0, b0);
    a0 = a, b0 = b, c0 = c;
  }
  cout << max(max(a0, b0), c0);

  return 0;
}