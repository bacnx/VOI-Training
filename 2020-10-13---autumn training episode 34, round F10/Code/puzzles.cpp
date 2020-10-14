#include<bits/stdc++.h>
using namespace std;

int f[26][26];

void add(int begin, int end, int size) {
    if (begin == end) f[begin][end] += size;

    for (int i = 0; i < 26; i++)
        if ((i != begin || i != end) && f[i][begin])
            f[i][end] = max(f[i][end], f[i][begin] + size);
    f[begin][end] = max(f[begin][end], size);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("puzzles.inp", "r", stdin);
    freopen("puzzles.out", "w", stdout);

    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        add(s.front()-'a', s.back()-'a', (int)s.size());
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = max(ans, f[i][i]);
    cout << ans;

    return 0;
}