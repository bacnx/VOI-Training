#include <bits/stdc++.h>
using namespace std;

const string NAME = "sell";

long long Rand(long long l, long long r) {
  return l + (long long)rand() * (long long)rand() % (r - l + 1);
}
// long long Rand(long long l, long long h)
// {
//     return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
//                 (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
//                 (long long)rand() * (RAND_MAX + 1) +
//                 rand()) % (h - l + 1);
// }

int main() {
  srand(time(NULL));

  system(("g++ " + NAME + ".cpp -o " + NAME).c_str());
  system(("g++ " + NAME + "_trau.cpp -o" + NAME + "_trau").c_str());

  for (int iTest = 1; iTest <= 100; iTest++) {
    ofstream inp((NAME + ".inp").c_str());
      int n = Rand(1, 100), k = (Rand(1, n));
      inp << n << " " << k << '\n';
      for (int i = 1; i <= n; i++)
        inp << Rand(1, 10) << ' ';
    inp.close();

    system(("./" + NAME + "_trau").c_str());
    system(("./" + NAME).c_str());
    
    if (system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0) {
      cout << "Test " << iTest << ": WRONG!\n";
      return 0;
    } else {
      cout << "Test " << iTest << ": CORRECT!\n";
    }
  }

  return 0;
}