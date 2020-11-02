#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int n;
long long p;
long long a[MAX];

map<long long, int> mp;

int cntMax(vector<int> v) {
    int ans[2]; ans[0] = ans[1] = 0;
    for (int i = 0; i < (int)v.size(); i++)
        ans[i%2] += v[i];
    return max(ans[0], ans[1]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    sort(a + 1, a + n + 1);

    if (p == 1) {
        int ans = 0;
        for (int i = 1; i <= n; i++) if (a[i] != a[i-1]) ans++;
        cout << ans;
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) if (a[i] != a[i-1] && mp[a[i]] > 0) {
        vector<int> v;
        long long tmp = a[i];
        while (mp[tmp] > 0) {
            v.push_back(mp[tmp]);
            mp[tmp] = 0;
            tmp *= p;
        }
        ans += cntMax(v);
    }
    cout << ans;

    return 0;
}