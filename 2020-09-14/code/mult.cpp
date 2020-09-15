#include<bits/stdc++.h>
using namespace std;

long long baseNum(long long n, int base) {
  long long temp = 0;
  int cnt = 0;
  while (n != 0) {
    if (n % base >= 10) return -1;
    // temp = temp*10 + n%base;
    temp = n%base * pow(10, cnt++) + temp;
    n /= base;
  }
  return temp;

  long long ans = 0;
  while (temp != 0) {
    ans = ans*10 + temp%10;
    temp /= 10;
  }

  return ans;
}

int main() {
  // freopen("mult.inp", "r", stdin);
  // freopen("mult.out", "w", stdout);

  long long p, q, pq; cin >> p >> q >> pq;
  long long t = p * q;

  cout << baseNum(t, 2);
  return 0;
  
  for (int i = 2; i <= 16; i++) {
    if (baseNum(t, i) == pq) {
      cout << i;
      return 0;
    }
  }
  cout << 0;

  return 0;
}