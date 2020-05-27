#include <bits/stdc++.h>
using namespace std;

struct line { int a, b; };
const int maxn = 1e5+1;
int n;
line a[maxn];
vector<int> lis;

bool cmp(const line &a, const line &b) {
    if (a.a != b.a) return a.a > b.a;
    return a.b < b.b;
}

int sb(int a) {
    int l = 0, r = (int)lis.size()-1, mid, res;
    while (l <= r) {
        mid = (l+r)/2;
        if (a < lis[mid]) { res = mid; r = mid - 1; }
        else l = mid + 1;
    }
    return res;
}

int main()
{
    freopen("doanthang.inp", "r", stdin);
    freopen("doanthang.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b;
    sort(a+1, a+n+1, cmp);

    // for (int i = 1; i <= n; i++)
    //     cout << a[i].a << " " << a[i].b << endl;
    lis.push_back(a[1].b);
    for (int i = 2; i <= n; i++)
        if (a[i].b >= lis.back()) lis.push_back(a[i].b);
        else lis[sb(a[i].b)] = a[i].b;
    cout << lis.size();

    return 0;
}