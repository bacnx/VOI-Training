#include <bits/stdc++.h>
using namespace std;

const string NAME = "set";

long long Rand(long long l, long long r) {
  return l + (long long)rand() * (long long)rand() % (r - l + 1);
}

int main() {
  srand(time(NULL));
  
  system(("g++ " + NAME + ".cpp -o " + NAME).c_str());
  system(("g++ " + NAME + "_trau.cpp -o " + NAME + "_trau").c_str());
  
  for (int iTest = 1; iTest <= 1000; iTest++) {
    ofstream inp((NAME + ".inp").c_str());
      int t = Rand(1, 1); inp << t << '\n';
      while (t--) {
        int k =  Rand(2, 10), a = Rand(1, 9), b = Rand(a+1, 10);
        inp << k << ' ' << a << ' ' << b << '\n';
        int m = Rand(1, 50); inp << m << '\n';
        while (m--) {
          int p = Rand(1, 49), q = Rand(p+1, 50);
          inp << p << ' ' << q << '\n';
        }
      }
    inp.close();

    system(("./" + NAME + " && ./" + NAME + "_trau").c_str());
    if (system(("diff " + NAME + ".ans " + NAME + ".out").c_str()) != 0) {
      cout << "Test " << iTest << ": WRONG!\n";
      return 0;
    } else 
      cout << "TEST " << iTest << ": CORRECT!\n";
  }

  return 0;
}