#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll m, n, gcd;
string a, b;
vector<int> cntCharA[26], cntCharB[26];

void init() {
    for (int i = 0; i < (int)a.size(); i++)
        cntCharA[a[i]-'a'].push_back(i);
    for (int i = 0; i < (int)b.size(); i++)
        cntCharB[b[i]-'a'].push_back(i);
}

ll numSame(int c) {
    map<int, int> mp;
    ll ans = 0;

    for (int i : cntCharA[c])
        mp[i%gcd]++;
    for (int i : cntCharB[c])
        ans += (ll)mp[i%gcd];
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("hamming.inp", "r", stdin);
    freopen("hamming.out", "w", stdout);

    int st; cin >> st;
    cin >> m >> n;
    cin >> a >> b;

    init();
    gcd = __gcd((ll)a.size(), (ll)b.size());
    ll lcm = (ll)a.size() * b.size() / gcd;
    
    ll ans = lcm;
    for (int i = 0; i < 26; i++)
        ans -= numSame(i);
    ans = a.size() * m / lcm * ans;
    
    cout << ans;

    return 0;
}