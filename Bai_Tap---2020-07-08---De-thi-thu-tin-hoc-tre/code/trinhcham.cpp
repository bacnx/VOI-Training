#include <bits/stdc++.h>
using namespace std;

int main() {
  system("g++ SEQLEN.cpp -o seqlen");
  system("g++ seqlen_trau.cpp -o seqlen_trau");
  
  for (int iTest = 1; iTest <= 10000; iTest++) {
    ofstream inp("seqlen.inp");
    inp << iTest;
    inp.close();

    system("./seqlen && ./seqlen_trau");

    if (system("diff seqlen.ans seqlen.out") != 0) {
      cout << iTest << ": WRONG!\n";
      break;
    } cout << iTest << ": CORECT!\n";
  }

  return 0;
}