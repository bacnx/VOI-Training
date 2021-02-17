// http://csloj.ddns.net/problem/591
#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pii;
#define fi first
#define se second

#define INF 1e18
#define N 5003

struct State {
    int u;
    ll cost;
    int id, value; // chi so cua cua hang da mua va gia dong xu

    State(const int &_u = 0, const ll &_cost = INF, int _id = 0, int _value = 0) {
        u = _u; cost = _cost; id = _id; value = _value;
    }

    bool operator < (const State &b) const {
        if (cost != b.cost) {
            return cost < b.cost;
        } else {
            if (value != b.value) {
                return value > b.value;
            } else {
                return id < b.id;
            }
        }
    }

    bool operator > (const State &b) const {
        return !(State(u, cost, id, value) < b);
    }
};

bool minimize(State &a, State b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int n, m, k;
int u0, v0;
int value[N];
vector<pii> adj[N];

State dp[N][2];

void initDp() {
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = State(i, INF, 0, 0);
    }
}

void dijkstra() {
    initDp();
    priority_queue<State, vector<State>, greater<State>> pq;

    adj[0].push_back(pii(u0, 0));
    dp[0][0] = State(0, 0, 0, 0);
    pq.push(dp[0][0]);

    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        int u = cur.u, isChoose = (cur.id != 0);
        if (cur.cost != dp[u][isChoose].cost) continue;

        for (pii e : adj[u]) {
            int v = e.fi, w = e.se;

            if (isChoose == 0) {
                State newState = cur;
                newState.cost += w;
                newState.u = v;
                if (minimize(dp[v][0], newState)) {
                    pq.push(dp[v][0]);
                }

                if (value[v]) {
                    newState.cost += value[v];
                    newState.id = v;
                    newState.value = value[v];
                    if (minimize(dp[v][1], newState)) {
                        pq.push(dp[v][1]);
                    }
                }
            } else {
                State newState = cur;
                newState.cost += w;
                newState.u = v;
                if (minimize(dp[v][1], newState)) {
                    pq.push(dp[v][1]);
                }

                if (value[v]) {
                    newState.cost += -newState.value + value[v];
                    newState.id = v;
                    newState.value = value[v];
                    if (minimize(dp[v][1], newState)) {
                        pq.push(dp[v][1]);
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    cin >> u0 >> v0;
    for (int i = 0; i < k; i++) {
        int u, p; cin >> u >> p;
        value[u] = p;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }

    dijkstra();

    cout << dp[v0][1].cost << ' ' << dp[v0][1].id;

    return 0;
}