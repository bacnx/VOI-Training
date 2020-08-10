#include<bits/stdc++.h>
using namespace std;

const int maxN = 3e5+1, maxA = 3e6+1;
int n, k, a[maxN], cnt[maxA];
bool isL[maxA];
vector<int> u[maxA];

void init_u() {
  for (int i = 2; i*2 < maxA; i++) {
    for (int j = 2; j*i < maxA; j++) {
      if (isL[i*j])
        u[i*j].push_back(i);
    }
  }
}

void add(int a) {
  // int n = (int)sqrt(a);
  // for (int i = 1; i <= n; i++) {
  //   if (a % i == 0) {
  //     cnt[i]++;
  //     cnt[a/i]++;
  //   }
  // }
  // if (n * n == a)
  //   cnt[n]--;
  cnt[1]++; cnt[a]++;
  for (int i = 0; i < (int)u[a].size(); i++)
    cnt[u[a][i]]++;
}

int main() {
  ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    isL[a[i]] = true;
  }

  init_u();
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    add(a[i]);
    mx = max(mx, a[i]);
  }
  
  for (int i = mx; i >= 1; i--)
    if (cnt[i] >= n-k) {
      cout << i;
      return 0;
    }

  return 0;
}