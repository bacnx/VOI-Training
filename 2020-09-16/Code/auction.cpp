#include<bits/stdc++.h>
using namespace std;

int a, b;
vector<bool> isPrime(100005, true);

void initIsPrime() {
  int n = 100000;
  for (int i = 2; i <= n; i++) {
    if (!isPrime[i]) continue;
    for (int j = 2; i*j <= n; i++)
      isPrime[i*j] = false;
  }
}



int main() {
  

  return 0;
}