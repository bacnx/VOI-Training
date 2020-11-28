#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 100005;

struct Node {
    int go[4];
    bool isEnd;

    Node() {
        memset(go, -1, sizeof go);
        isEnd = false;
    }
};

vector<Node> trie;

int addNode() {
    trie.push_back(Node());
    return (int)trie.size() - 1;
}

// ============================================================================


int n;
vector<pii> adj[MAX];

void Read() {
    int _n; cin >> _n;
    string _s; cin >> _s;
    vector<string> p(_n);
    for (int i = 0; i < _n; i++) cin >> p[i];

    n = (int)_s.size();

    // =========================================================================

    /* init id */ int id[277]; {
        id['a'] = 0;
        id['b'] = 1;
        id['c'] = 2;
        id['h'] = 3;
    }

    // make trie
    addNode();

    for (string s : p) {
        int cur = 0;
        for (char c : s) {
            // cout << cur << ' ';
            int nx = id[c];
            // cout << nx << ' ';
            if (trie[cur].go[nx] == -1) {
                addNode();
                trie[cur].go[nx] = (int)trie.size()-1;
            }
            cur = trie[cur].go[nx];
            // cout << addNode() << '\n';
        }
        trie[cur].isEnd = true;
    }

    // =========================================================================

    // make graph
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = i; j < n; j++) {
            int c = id[_s[j]];
            if (trie[cur].go[c] == -1) break;
            cur = trie[cur].go[c];
            if (trie[cur].isEnd) adj[i].push_back(pii(j+1, j-i));
        }
    }
}

void solveSub1() {
    int n; cin >> n;
    if (n != 1) return ;
    string s; cin >> s;
    string p; cin >> p;

    int ans = 0;
    n = (int)s.size(); int m = (int)p.size();
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (cnt < n && s[cnt + i] == p[cnt % m]) cnt++;
        ans = max(ans, cnt - cnt % m);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("laugh.inp", "r", stdin);
    freopen("laugh.out", "w", stdout);

    Read();

    for (int i = 0; i < n; i++) {
        cout << i << ":  ";
        for (pii j : adj[i]) cout << j.first << ' ';
        cout << '\n';
    }

    return 0;
}