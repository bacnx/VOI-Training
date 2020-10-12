#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("eoe.inp", "r", stdin);
    freopen("eoe.out", "w", stdout);
    string s; cin >> s;

    int x, y; {
        string s; 
        cin >> s;
        if (s == "Even") x = 0; else x = 1;
        cin >> s;
        if (s == "Even") y = 0; else y = 1;
    }

    s = s + "+ ";
    int ans = 0, t = -1, a;
    for (int i = 0; i < (int)s.size()-1; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
            if (s[i] == '*') continue;
            ans += t; ans %= 2;
            t = -1;
            continue;
        } else if (s[i] >= '0' && s[i] <= '9') {
            if (s[i+1] >= '0' && s[i+1] <= '9') continue;
            a = s[i] - '0';
        } else if (s[i] == 'x') a = x;
        else if (s[i] == 'y') a = y;

        if (t == -1) t = a;
        else t = t * a % 2;
    }

    if (ans == 0) cout << "Even";
    else cout << "Odd";

    return 0;
}