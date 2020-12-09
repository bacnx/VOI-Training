#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pii;
const int MAX = 100005;

int n, T;
pii a[MAX];
ll s[MAX];
int ans = 0;

int solve(int l) {
    priority_queue<int> pq;
    int res = l;
    ll sum = s[l];
    for (int i = 1; i <= l; i++) pq.push(a[i].second);

    while (!pq.empty() && sum > T) {
        sum -= pq.top();
        pq.pop();
        res--;
    }
    ans = max(ans, res);
    return (sum <= T) ? res : -1;
}

void sb(int l, int r) {
    if (l > r) return ;
    int mid = (l + r) / 2;
    int tmp = solve(mid);
    if (tmp != -1) {
        sb(l, mid - 1);
        sb(mid + 1, r);
    } else sb(l, mid - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("cake.inp", "r", stdin);
    freopen("cake.out", "w", stdout);

    cin >> n >> T;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
        s[i] = s[i-1] + a[i].second + a[i].first - a[i-1].first;

    
    if (n < 1000) {
        sb(1, n);
        cout << ans;
    } else {
        int res = 0;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            int tmp = solve(mid);
            if (tmp != -1) {
                res = max(res, tmp);
                l = mid + 1;
            } else r = mid - 1;
        }
        cout << res;
    }


    return 0;
}