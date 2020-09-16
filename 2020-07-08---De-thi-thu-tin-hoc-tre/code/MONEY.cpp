#include <bits/stdc++.h>
using namespace std;

#define int long long

const int gMod = 1e6, sMod = 17, kMod = 29;
int g, s, k, n;
int gP, sP, kP;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  freopen("money.inp", "r", stdin);
  freopen("money.out", "w", stdout);

  cin >> g >> s >> k;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int p, q, r; cin >> p >> q >> r;
    gP += p, sP += q, kP += r;
  }

  gP += sP / sMod; sP %= sMod;
  sP += kP / kMod; kP %= kMod;

  if (k < kP) {
    k += kMod; s--;
  } k -= kP;
  if (s < sP) {
    s += gMod; g--;
  } s -= sP;
  if (g < gP) {
    cout << "-1"; return 0;
  } g -= gP;

  cout << g << ' ' << s << ' ' << k;

  return 0;
}