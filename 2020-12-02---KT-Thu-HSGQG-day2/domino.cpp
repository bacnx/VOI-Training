#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 502;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int m, n;
int a[MAX][MAX];


bool check(pii u, int i) {
    int x = u.first + dx[i] * 2;
    int y = u.second + dy[i] * 2;

    return 1 <= x && x <= m
        && 1 <= y && y <= n;
}

void bfs(pii u0) {
    int res = 0;
    queue<pii> q;
    q.push(u0);

    while (!q.empty()) {
        pii u = q.front(); q.pop();

        for (int i = 0; i < 4; i++) if (check(u, i)) {
            int x = u.first + dx[i];
            int y = u.second + dy[i];

            if (a[x][y] != 0 && a[x][y] == a[x + dx[i]][y + dy[i]]) {
                q.push(pii(x + dx[i], y + dy[i]));
                a[x][y] = a[x + dx[i]][y + dy[i]] = 0;
                res++;
            }
        }
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("domino.inp", "r", stdin);
    freopen("domino.out", "w", stdout);

    cin >> m >> n;
    for (int i = 1, _n = (n * m - 1)/2; i <= _n; i++) {
        int u, v, x, y; cin >> u >> v >> x >> y;
        a[u][v] = a[x][y] = i;
    }

    pii root;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) if (a[i][j] == 0) {
        root = pii(i, j);
        break;
    }

    bfs(root);

    return 0;
}