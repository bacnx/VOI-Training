#include<bits/stdc++.h>
using namespace std;

vector<bool> isPrime(100005, true);

void initIsPrime() {
  int n = 100000;
  for (int i = 2; i <= n; i++) {
    if (!isPrime[i]) continue;
    for (int j = 2; i*j <= n; j++)
      isPrime[i*j] = false;
  }
}

bool isSym(int n) {
  int temp = n;
  int _n = 0;
  while (temp != 0) {
    _n = _n*10 + temp%10;
    temp /= 10;
  }
  return n == _n;
}

int main() {
  freopen("auction.inp", "r", stdin);
  freopen("auction.out", "w", stdout);

  int a, b; cin >> a >> b;
  initIsPrime();
  int res = 0;
  for (int i = a; i <= b; i++)
   if (isPrime[i] && isSym(i))
    res++;
  
  cout << res;

  return 0;
}