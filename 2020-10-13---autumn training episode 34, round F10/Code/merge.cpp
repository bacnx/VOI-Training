#include<bits/stdc++.h>
using namespace std;

string Read() {
    vector<string> v;
    string s;

    while (true) {
        cin >> s;
        if (s[0] < 'a') break;
        v.push_back(s);
    }
    int k = 0;
    for (int i = 0; i < s.size(); i++)
        k = k*10 + s[i]-'0';

    return v[k-1];
}

int main() {
    freopen("merge.inp", "r", stdin);
    freopen("merge.out", "w", stdout);

    int n; cin >> n;

    string ans = "";
    while (n--)
        ans = ans + Read() + " ";
    
    cout << ans;

    return 0;
}