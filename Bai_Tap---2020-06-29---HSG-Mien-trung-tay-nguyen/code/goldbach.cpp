#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(1e6, true);

void initIsPrime() {
  isPrime[1] = false;
  for (int i = 2; i < 1e6; i++)
    for (int j = 2; i * j < 1e6; j++)
      isPrime[i*j] = false;
}

int main() {
  int n; cin >> n;
  initIsPrime();
  int res = 0;
  for (int i = 2; i <= n/2; i++)
    if (isPrime[i] && isPrime[n-i])
      res ++;

  cout << res;

  return 0;
}