#include <bits/stdc++.h>
using namespace std;

string a, b, res;

int main()
{
    freopen("hoanvi.inp", "r", stdin);
    freopen("hoanvi.out", "w", stdout);

    cin >> a >> b;
    sort(a.begin(), a.end(), greater<int>());
    int n = (int)a.size();

    if (a.size() < b.size()) {
        cout << a; 
        return 0;
    }
    int br = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n; j++)
            if (a[j] <= b[i]) {
                if (a[j] < b[i]) br = 1;
                swap(a[i], a[j]);
                break; 
            }
        sort(a.begin()+i+1, a.end(), greater<int>());
        if (br) break;
    }
    cout << a;

    return 0;
}