#include<bits/stdc++.h>
using namespace std;

int f[26][26];

void add(int begin, int end, int size) {
    if (begin == end) f[begin][end] += size;
    else if (f[begin][end] < size) f[begin][end] = size;
    else return ;

    for (int i = 0; i < 26; i++)
        if ((i != begin || i != end) && f[i][begin])
            f[i][end] = max(f[i][end], f[i][begin] + size);
}

void tests() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    } cout << '\n';
}

int main() {
    freopen("puzzles.inp", "r", stdin);
    freopen("puzzles.out", "w", stdout);

    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        add(s.front()-'a', s.back()-'a', (int)s.size());
        // if (s == "c") cout << f['k'-'a']['c'-'a'] << '\n';
        // tests();
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = max(ans, f[i][i]);
    cout << ans;

    return 0;
}