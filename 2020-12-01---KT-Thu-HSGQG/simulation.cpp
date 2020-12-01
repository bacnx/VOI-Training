#include<bits/stdc++.h>
using namespace std;

int n;
int x[100005], y[100005];
int sx[100005], sy[100005];
int res[100005];

void update(int id) {
    int nx, ny; cin >> nx >> ny;
    int dx = nx - x[id], dy = ny - y[id];
    x[id] = nx, y[id] = ny;
    
    for (int i = id; i <= n; i++) {
        res[i] = res[i-1];
        sx[i] += dx, sy[i] += dy;
        if (sx[i] * sx[i-1] < 0) res[i]++;
        if (sy[i] * sy[i-1] < 0) res[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("simulation.inp", "r", stdin);
    freopen("simulation.out", "w", stdout);

    cin >> n;
    sx[0] = sy[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        res[i] = res[i-1];
        sx[i] = sx[i-1] + x[i];
        sy[i] = sy[i-1] + y[i];
        if (sx[i] * sx[i-1] < 0) res[i]++;
        if (sy[i] * sy[i-1] < 0) res[i]++;
    }

    int m; cin >> m;
    int id = 1;
    while (m--) {
        char c; cin >> c;
        if (c == 'B') {
            if (id != 1) id--;
        } else if (c == 'F') {
            if (id != n) id++;
        } else if (c == 'C') update(id);
        else cout << res[n] << '\n';
    }

    return 0;
}