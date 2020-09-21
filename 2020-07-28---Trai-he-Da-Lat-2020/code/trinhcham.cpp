#include <bits/stdc++.h>
using namespace std;

const string _name = "flycar";
const int nTest = 100;

const int nMax = 10;
const int aMax = 10;

long long Rand(long long a, long long b) {
  if (a > b) return 0;
  return a + (long long)rand() * (long long)rand() % (b - a + 1);
}

int main() {
  srand(time(NULL));

  system(("g++ " + _name + ".cpp -o" + _name).c_str());
  system(("g++ " + _name + "_check.cpp -o" + _name + "_check").c_str());

  for (int iTest = 1; iTest <= nTest; iTest++) {
    ofstream inp((_name + ".inp").c_str());
      int n = Rand(2, nMax);
      int k = Rand(1, n-1);
      inp << n << ' ' << k << '\n';
      for (int i = 1; i <= n; i++) {
        int a = Rand(0, aMax);
        inp << a << ' ';
      }
    inp.close();

    system(("./" + _name).c_str());
    system(("./" + _name + "_check").c_str());

    if (system(("diff " + _name + ".out " + _name + ".ans").c_str()) != 0) {
      cout << "Test " << iTest << ": WRONG\n";
      break;
    } else cout << "Test " << iTest << ": Correct\n";
  }

  return 0;
}