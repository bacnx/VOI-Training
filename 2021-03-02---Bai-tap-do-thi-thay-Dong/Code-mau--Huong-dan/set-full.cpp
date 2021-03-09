//Dai Ca Di Hoc
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
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "set"

using namespace std;

typedef long long ll;
typedef long double ld;

ll a, b, k;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    int T, m;
    cin >> T;
    while (T--){
        cin >> k >> a >> b;
        ll d = b-a;
        while (d % k == 0) d /= k;
        for (int i = 2; i <= sqrt(k); i++)
            if (k % i == 0)
		 {
                while (d % i == 0) d /= i;
                int x = k/i;
                while (d % x == 0) d /= x;
            }
        int m;
        ll p, q;
        cin >> m;
        while (m--){
            cin >> p >> q;
            if (p < q && (q-p) % d == 0) cout << "YES\n";
                else cout << "NO\n";
        }
    }
    return 0;
}

