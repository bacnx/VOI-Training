#include<bits/stdc++.h>
using namespace std;

const string _name = "floodfill";
const int nTest = 100;
const int nMax = 5;
const int aMax = 5;

long long Rand(long long a, long long b) {
  if (a > b) return 0;
  return a + (long long)rand() * (long long)rand() % (b - a + 1);
}

int main() {
  srand(time(NULL));

  system(("g++ " + _name + ".cpp -o " + _name).c_str());
  system(("g++ " + _name + "_full.cpp -o " + _name + "_full").c_str());

  for (int iTest = 1; iTest <= nTest; iTest++) {
    ofstream inp((_name + ".inp").c_str());
      int n = Rand(1, nMax);
      inp << n << '\n';
      for (int i = 1; i <= n; i++) {
        int a = Rand(1, aMax);
        inp << a << ' ';
      }
    inp.close();

    system(("./" + _name).c_str());
    system(("./" + _name + "_full").c_str());

    if (system(("diff " + _name + ".out " + _name + ".ans").c_str()) != 0) {
      cout << "Test" << iTest << ": WRONG!\n";
      break;
    } else cout << "Test" << iTest << ": Correct!\n";
  }

  return 0;
}