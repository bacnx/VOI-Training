#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265

struct point {
    double x, y;
    int alpha;

    point (double _x, double _y, int _alpha) {
        x = _x, y = _y;
        alpha = _alpha;
    }

    double dist(const point &u) {
        return sqrt((double)(x - u.x)*(x - u.x) + (double)(y - u.y) * (y - u.y));
    }
};

/*
    fd: tiến
    lt: rẽ trái
    rt: rẽ phải
    br: lùi 
*/

void change(point &u, string s, int num) {
    if (s == "lt" || s == "rt") {
        if (s == "lt") u.alpha = (u.alpha + num)%360;
        else u.alpha = (u.alpha - num)%360;
        return ;
    }
    
    if (s == "br") u.alpha = (u.alpha + 180) % 360;
    u.x += num * cos(u.alpha * PI / 180);
    u.y += num * cos(u.alpha * PI / 180);
}

void solve() {
    int n; cin >> n;
    point p(0, 0, 0);
    while (n--) {
        string s; cin >> s;
        int num; cin >> num;
        change(p, s, num);
    }
    double ans = point(0, 0, 0).dist(p);
    if ((int)(ans + 0.5) > (int)ans) ans++;
    cout << (int)ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("logo.inp", "r", stdin);
    freopen("logo.out", "w", stdout);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}