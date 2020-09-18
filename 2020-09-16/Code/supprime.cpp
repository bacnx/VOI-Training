#include<bits/stdc++.h>
using namespace std;

vector<bool> isPrimeArr(100005, true);
int x;

bool isPrime(int x) {
  if (x < 2) return false;
  if (x == 2 || x == 3) return true;
  int n = (int)sqrt(x);
  for (int i = 2; i <= n; i++)
    if (x % i == 0) return false;
  return true;
}

void solve() {
  int n = 100005;
  int cnt = 0, cnt1 = 0;

  for (int i = 2; i <= n; i++) {
    if (isPrimeArr[i]) {
      cnt++;
      if (isPrime(cnt)) {
        cnt1++;
        if (cnt1 == x) {
          cout << i;
          return ;
        }
      }
      for (int j = 2; j*i <= n; j++)
        isPrimeArr[i*j] = false;
    }
  }
}

int main() {
  freopen("supprime.inp", "r", stdin);
  freopen("supprime.out", "w", stdout);

  cin >> x;
  
  solve();

  return 0;
}