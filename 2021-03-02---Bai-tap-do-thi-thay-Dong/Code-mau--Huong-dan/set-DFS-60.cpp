#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 505
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "set"

using namespace std;

typedef long long ll;
typedef long double ld;

ll a, b, k, cnt;
int dd[maxn][maxn];
vector <int> c[maxn];

void DFS(int u, int v){
    if (dd[u][v] == cnt) return;
    dd[u][v] = cnt;
    c[u].PB(v);
    if (v+1 < maxn) DFS(u+1, v+1);
    if (u % k == 0 && v % k == 0) DFS(u/k, v/k);
    for (int i = 0; i < c[v].size(); i++) {
        int x = c[v][i];
        DFS(u, x);
    }

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    int T;
    cin >> T;
    for( cnt = 1; cnt <= T; cnt++){
		for (int i = 0; i < maxn; i++) c[i].clear();
        cin >> k >> a >> b;
        DFS(a,b);
        int m;
        ll p, q;
        cin >> m;
        while (m--){
            cin >> p >> q;
            if (dd[p][q]==cnt) cout << "YES\n";
                else cout << "NO\n";
        }
    }
    return 0;
}

