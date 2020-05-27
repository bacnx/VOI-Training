#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;

int n, m, a[maxn];

void test(int l, int r, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = l; i <= r; i++) pq.push(a[i]);
    while (--k) pq.pop();
    cout << pq.top() << endl;
}

int main()
{
    freopen("find.inp", "r", stdin);
    freopen("find.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int l, r, k;
    while (m--) {
        cin >> l >> r >> k; 
        test(l, r, k);
    }

    return 0;
}