#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int q, k;

void solveSub3() {
    vector<pii> a;
    int cntShow = 0;

    {
    long long sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= q; i++) {
        string s; cin >> s;
        cntShow++;
        if (s == "eat") break;
        
        int t, c; cin >> t >> c;
        a.push_back(pii(c, t));
        pq.push(t);
        sum += 1LL * t;

        if (i > k) {
            sum -= 1LL * pq.top(); pq.pop();
        }
        cout << sum << ' ';
    }
    }

    sort(a.begin(), a.end());
    // for (int i = max(0, (int)a.size() - k); i < (int)a.size(); i++) sum += 1LL * a[i].second;

    // cout << sum;
    // for (int i = cntShow; i <= q; i++) {
    //     if (!a.empty()) {
    //         sum -= 1LL * a.back().second; a.pop_back();
    //         if ((int)a.size() - k >= 0) sum += 1LL * a[(int)a.size() - k].second;
    //         cout << sum << ' ';
    //     } else cout << "0 ";
    // }
}

int main() {
    freopen("B.inp", "r", stdin); // ------------------------------------??
    
    int t; cin >> t;
    cin >> q >> k;
    
    if (t == 3) {
        solveSub3();
        return 0;
    }

    return 0;
}