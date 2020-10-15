#include <bits/stdc++.h>
using namespace std;

const string NAME = "puzzles";

long long Rand(long long l, long long r) {
  return l + (long long)rand() * (long long)rand() % (r - l + 1);
}

int main() {
  srand(time(NULL));
  
  system(("g++ " + NAME + ".cpp -o " + NAME).c_str());
  system(("g++ " + NAME + "_trau.cpp -o " + NAME + "_trau").c_str());
  
  for (int iTest = 1; iTest <= 10000; iTest++) {
    ofstream inp((NAME + ".inp").c_str());
      int n = Rand(1, 20); inp << n << '\n';
      while (n--) {
        int k =  Rand(1, 10);
        while (k--)
            inp << (char)Rand((int)'a', (int)'z');
        inp << ' ';
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