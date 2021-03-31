#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct State {
    int score, cntStep;
    int x1, y1, x2, y2;
    State() {}
    State(int _score, int _cntStep, int _x1, int _y1, int _x2, int _y2) {
        score = _score;
        cntStep = _cntStep;
        x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
    }
};

const int dx[] = {1, 0};
const int dy[] = {0, 1};
const int maxN = 202;

int m, n, a[maxN][maxN];
int d[maxN][maxN][maxN]; // d[x1][y1][x2][y2]: điểm nhiều nhất khi ở (x1; y1) và (x2; y2);
// #define D(s) d[s.x1][s.y1][s.x2][s.y2]
// int res = -100000;

// bool check(int x1, int y1, int x2, int y2) {
//     if (x1 < 1 || x2 < 1) return false;
//     if (x1 > m || x2 > m) return false;
//     if (y1 < 1 || y2 < 1) return false;
//     if (y1 > n || y2 > n) return false;

//     if (x1 == x2 && y1 == y2) return false;
//     return true;
// }

// void bfs() {
//     memset(d, -100000, sizeof(d));
//     queue<State> q;
//     d[1][1][1][1] = 0;
//     q.push(State(0, 0, 1, 1, 1, 1));

//     while (!q.empty()) {
//         State cur = q.front(); q.pop();
//         if (cur.score != D(cur)) continue;
//         if (cur.cntStep == m + n - 3) {
//             res = max(res, cur.score);
//             continue;
//         }

//         for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
//             int x1 = cur.x1 + dx[i], y1 = cur.y1 + dy[i];
//             int x2 = cur.x2 + dx[j], y2 = cur.y2 + dy[j];
//             int newScore = cur.score + a[x1][y1] + a[x2][y2];
//             State nxt(newScore, cur.cntStep + 1, x1, y1, x2, y2);

//             if (newScore > D(nxt)) {
//                 D(nxt) = newScore;
//                 q.push(nxt);
//             }
//         }
//     }
// }

int main() {
    // cin >> m >> n;
    // for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
    //     cin >> a[i][j];
    
    // memset(d, -100000, sizeof(d));
    // cout << d[1][2][3][4];

    return 0;
}