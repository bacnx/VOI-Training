#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5+5;

int n, a[maxN];
int sumr[maxN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  int aMin = a[1], aMax = a[1];
  for (int i = 1; i <= n; i++) {
    aMin = min(aMin, a[i]);
    aMax = max(aMax, a[i]);
  }

  sumr[n+1] = 0;
  for (int i = n; i >= 1; i--)
    if (a[i+1] == aMax)
      sumr[i] = 1;
    else 
      sumr[i] = sumr[i+1] + 1;
  
  

  return 0;
}