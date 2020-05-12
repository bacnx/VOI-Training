#include <bits/stdc++.h>
using namespace std;

int us[10004];

int uoc(int a) {
    int result = 0;
    for (int i = 1; i <= (int)sqrt(a); i++)
        if (a % i == 0) result+=2;
    if (a == (int)sqrt(a)*sqrt(a)) result--;
    return result;
}

int main()
{
    freopen("uocso.inp", "r", stdin);
    freopen("uocso.out", "w", stdout);

    int a, b;
    cin >> a >> b;
    
    int Min = 0, Cmin = 0, Count = 0;
    for (int i = a; i <= b; i++) {
        us[i-a] = uoc(i);
        Cmin = max(Cmin, us[i-a]);
    }
    for (int i = a; i <= b; i++) {
        if (us[i-a] == Cmin) {
            if (Min == 0) Min = i;
            Count++;
        }
        // cout << i << " " << us[i-a] << endl;
    }
    cout << Min << " " << Cmin << " " << Count;

    return 0;
}