#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+1;
int n, a[maxn];
map<int, bool> m;

void sub1() {
    sort(a+1, a+n+1);
    int result = 0;
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            if (m.find(a[i]+a[j])->second)
                result+=2;
    cout << result;
}

void sub2() {
    long long result = 0;
    for (int i = 3; i <= n; i++){
        result += (long long)i-1;
        if ((i-1)%2) result--;
    }
    cout << result;
}

int main()
{
    freopen("qd.inp", "r", stdin);
    freopen("qd.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        m.insert(pair<int, bool>(a[i], true));
    }
    
    if (n <= 3000) sub1();
    else sub2();

    return 0;
}