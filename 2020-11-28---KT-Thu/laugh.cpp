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



int n;
vector<pii> adj[MAX];
int d[MAX];


void Read() {
    int _n; cin >> _n;
    string _s; cin >> _s;
    vector<string> p(_n);
    for (int i = 0; i < _n; i++) cin >> p[i];

    n = (int)_s.size();

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
            int nx = id[c];
            if (trie[cur].go[nx] == -1) {
                addNode();
                trie[cur].go[nx] = (int)trie.size()-1;
            }
            cur = trie[cur].go[nx];
        }
        trie[cur].isEnd = true;
    }


    // make graph
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = i; j < n; j++) {
            int c = id[_s[j]];
            if (trie[cur].go[c] == -1) break;
            cur = trie[cur].go[c];
            if (trie[cur].isEnd) adj[i].push_back(pii(j+1, j-i+1));
        }
    }
}


int dfs(int u) {
    if (d[u] > -1) return d[u];
    d[u] = 0;
    for (pii i : adj[u])
        d[u] = max(d[u], dfs(i.first) + i.second);
    return d[u];
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("laugh.inp", "r", stdin);
    freopen("laugh.out", "w", stdout);

    Read();
    memset(d, -1, sizeof d);

    int ans = 0;
    for (int i = 0; i < n; i++) if (d[i] == -1)
        ans = max(ans, dfs(i));
    
    cout << ans;

    return 0;
}



// void solveSub1() {
//     if (n != 1) return ;
//     string s; cin >> s;
//     string p; cin >> p;

//     int ans = 0;
//     n = (int)s.size(); int m = (int)p.size();
//     for (int i = 0; i < n; i++) {
//         int cnt = 0;
//         while (cnt < n && s[cnt + i] == p[cnt % m]) cnt++;
//         ans = max(ans, cnt - cnt % m);
//     }
//     cout << ans;
// }