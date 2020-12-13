#include <bits/stdc++.h>
using namespace std;

#define ll long long
const string name = "magicians";
const string _name = "magicians_trau";
const int nTest = 100;

const int maxN = 500;
const int maxM = 4;
const int maxA = 1e6;


ll Rand(ll l, ll r) {
    return l + 1LL * rand() * rand() % (r - l + 1);
}

int main() {
    srand(time(NULL));

    system(("g++ " + name + ".cpp -o " + name).c_str());
    system(("g++ " + _name + ".cpp -o " + _name).c_str());

    for (int iTest = 0; iTest < nTest; iTest++) {
        ofstream inp((name + ".inp").c_str());
            int n = Rand(1, maxN), m = Rand(1, maxM);
            inp << n << ' ' << m << '\n';

            for (int i = 1; i <= n; i++) {
                ll a = Rand(-maxA, maxA);
                inp << a << ' ';
            } inp << '\n';

            for (int i = 1; i <= m; i++)  {
                int l = Rand(1, n), r = Rand(l, n);
                inp << l << ' ' << r << '\n';
            }
        inp.close();

        system((name + ".exe").c_str());
        system((_name + ".exe").c_str());

        if (system(("fc " + name + ".out " + name + ".ans").c_str()) == true) {
            cout << "Test " << iTest << ": WRONG" << endl;
            // system("pause");
            break;
        } else cout << "Test " << iTest << ": Correct!";
    }

    return 0;
}