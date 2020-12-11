#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 3e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<pii> edge;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("dtree.inp", "r", stdin);
    freopen("dtree.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        edge.push_back(pii(u, v));
    }
    sort(edge.begin(), edge.end(), greater<pii>());

    int bit = n-1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < n; i++) {
        while (!pq.empty() && pq.top() <= i) pq.pop();
        if (!pq.empty()) bit--;
        while (!edge.empty() && edge.back().first == i) {
            pq.push(edge.back().second);
            edge.pop_back();
        }
    }

    int ans = 1;
    while (bit--) {
        ans = (ans << 1);
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans;

    return 0;
}