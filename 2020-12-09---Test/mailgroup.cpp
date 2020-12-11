#include<bits/stdc++.h>
using namespace std;

const int MAX = 200005;

int n, k;
int numChil[MAX];
int father[MAX];
int isSelect[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("mailgroup.inp", "r", stdin);
    freopen("mailgroup.out", "w", stdout);

    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        cin >> father[i];
        numChil[father[i]]++;
    }

    while (k--) {
        int t; cin >> t;
        vector<int> v;
        map<int, int> mp;
        int ans = t;
        for (int i = 0; i < t; i++) {
            int a; cin >> a;
            v.push_back(a);
            isSelect[a] = 1;
            ans += numChil[a];
        }

        for (int a : v) {
            if (isSelect[father[a]] == 1) {
                ans--;
                isSelect[father[a]]++;
            }
        }
        cout << ans << '\n';

        for (int a : v) isSelect[a] = 0;
    }

    return 0;
}