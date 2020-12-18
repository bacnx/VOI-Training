#include<bits/stdc++.h>
using namespace std;

struct Node {
    vector<int> go;
    vector<bool> type;
    Node() { 
        go.resize(26, -1); 
        type.resize(2, false);
    }
};

vector<Node> trie;

int addNode() {
    trie.push_back(Node());
    return trie.size() - 1;
}

void pushToTrie(string s, int type) {
    int cur = 0;
    for (char c : s) {
        if (trie[cur].go[c - 'a'] == -1) trie[cur].go[c - 'a'] = addNode();
        cur = trie[cur].go[c - 'a'];
        trie[cur].type[type] = true;
    }
}

int game(int id, int type) {
    for (int i = 0; i < 26; i++) {
        if (trie[id].go[i] == -1) continue;
        int nxt = trie[id].go[i];
        if (trie[nxt].type[type]) if (game(nxt, type ^ 1) == type)
            return type;
    }
    return type ^ 1;
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    addNode();
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        pushToTrie(s, 0);
    }
    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        pushToTrie(s, 1);
    }

    int ans = game(0, 0);
    if (ans == 0) cout << "Alice";
    else cout << "Bob";

    return 0;
}