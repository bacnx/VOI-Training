#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct Result {
    int k, d, x, y;

    Result() {}

    Result(int _k, int _d, int _x, int _y) {
        k = _k, d = _d, x = _x, y = _y;
    }

    bool operator < (const Result &r) {
        if (k != r.k) return k < r.k;
        if (d != r.d) return d > r.d;
        return 1LL * x * 1e6 + y > 1LL * r.x * 1e6 + r.y;
    }
};

int m, n;
vector<vector<int> > a;

bool check(int x, int y) {
    return 0 <= x && x < m && 0 <= y && y < n;
}

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

Result loang(int d) {
    queue<pii> q;
    vector<vector<bool> > fre(m, vector<bool>(n, true));
    Result res(0, 0, 0, 0);

    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (fre[i][j]) {
        fre[i][j] = false;
        q.push(pii(i, j));
        Result tmp(1, d, i, j);
        
        while (!q.empty()) {
            int u = q.front().first, v = q.front().second; q.pop();

            for (int i = 0; i < 4; i++) {
                int x = u + dx[i], y = v + dy[i];
                if (!check(x, y) || !fre[x][y]) continue;
                if (abs(a[u][v] - a[x][y]) != d) continue;

                tmp.k++;
                fre[x][y] = false;
                q.push(pii(x, y));
            }
        }
        if (res < tmp) res = tmp;
    }
    return res;
}

int main() {
    // freopen("C.inp", "r", stdin); // ----------------------------------------------------------??
    int t; cin >> t;
    cin >> m >> n;
    a.resize(m, vector<int>(n));
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

    // if (t == 1) {
    //     cout << m * n << ' ' << 0 << ' ' << 1 << ' ' << 1;
    //     return 0;
    // }

    if (t == 4) {
        Result res(0, 0, 0, 0);
        for (int d = 0; d <= 1; d++) {
            Result tmp = loang(d);
            if (res < tmp) res = tmp;
        }
        cout << res.k << ' ' << res.d << ' ' << res.x + 1 << ' ' << res.y + 1;
        return 0;
    }

    cout << m * n << ' ' << 0 << ' ' << 1 << ' ' << 1;

    return 0;
}