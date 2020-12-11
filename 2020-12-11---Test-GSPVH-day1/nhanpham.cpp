/*
    chặt nhị phân tím số ngày đầu tiên có <tổng nhân phẩm tích được> - <nghiệp> >= k
        <tổng nhân phẩm tích được> = num * (num + 1) / 2;
        <tổng nghiệp> = (num / n) * sum[n] + sum[num % n];
    
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 1e5 + 5;

int n, a[MAX];
ll k, sum[MAX];;

ll nhanPham(ll x) {
    return x * (x + 1) / 2
        - ((x / n) * sum[n] + sum[x % n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("nhanpham.inp", "r", stdin);
    freopen("nhanpham.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    ll l = 1, r = 1e5;
    ll tmpRes = r;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (nhanPham(mid * n) >= k) {
            tmpRes = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    ll res = (tmpRes - 1) * n;
    ll np = nhanPham(res);
    for (int i = 1; i <= n; i++) {
        res++;
        np = nhanPham(res);
        if (np >= k) break;
    }
    cout << res;

    return 0;
}