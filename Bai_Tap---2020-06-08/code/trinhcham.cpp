#include <bits/stdc++.h>
using namespace std;

const string NAME = "power";

long long Rand(long long l, long long r) {
  return l + (long long)rand() * (long long)rand() % (r - l + 1);
}

int main() {
  srand(time(NULL));

  system(("g++ " + NAME + "_trau.cpp -o " + NAME + "_trau").c_str());
  system(("g++ " + NAME + ".cpp -o " + NAME).c_str());

  for (int iTest = 1; iTest <= 100; iTest++) {
    ofstream inp((NAME + ".inp").c_str());
      int n = Rand(2, 10), k = Rand(1, 10);
      inp << n << ' ' << k << '\n';
      for (int i = 1; i <= n; i++)
        inp << Rand(1, 10) << ' ';
    inp.close();

    system(("./" + NAME + "_trau").c_str());
    system(("./" + NAME).c_str());

    if (system(("diff " + NAME + ".ans " + NAME + ".out").c_str()) != 0) {
      cout << "Test " << iTest << ": WRONG!\n";
      break;
    }
    cout << "Test " << iTest << ": CORECT!\n";
  }

  return 0;
}