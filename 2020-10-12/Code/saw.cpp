#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, k, h[100005];
int sumH[100005], LIM;

bool check(int k, int m) {
    int i = lower_bound(h, h+n, k, greater<int>()) - h;
    int s = sumH[i-1] - i*k;
    return s >= m;
}

int query(int m) {
    int l = 0, r = LIM, mid;
    int ans = 0;
    while (l <= r) {
        mid = (l + r)/2;
        if (check(mid, m)) {
            ans = mid;
            l = mid + 1;
        } else r = mid -1;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("saw.inp", "r", stdin);
    freopen("saw.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i];
        
    LIM = *max_element(h,h+n);
    sort(h, h+n, greater<int>());
    for (int i = 0; i < n; i++) cout << h[i] << ' '; cout << endl;
    sumH[0] = h[0];
    for (int i = 1; i < n; i++)
        sumH[i] = sumH[i-1] + h[i];
    
    while (k--) {
        int m; cin >> m;
        cout << query(m) << ' ';
    }

    return 0;
}