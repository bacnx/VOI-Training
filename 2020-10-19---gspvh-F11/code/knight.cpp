#include <bits/stdc++.h>
using namespace std;

const int MIN_CORD = -2002;
const int MAX_CORD = 4004;
const long long MOD = 998244353;

void add(long long &a, long long b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

const int dx[] = {-1, 1, 2, 2};
const int dy[] = {2, 2, -1, 1};

long long f[MAX_CORD - MIN_CORD + 1][MAX_CORD - MIN_CORD + 1];
#define f(i, j) f[i - MIN_CORD][j - MIN_CORD]

void initF() {
	f(0, 0) = 1;
	int sum, x, y, i, nx, ny;

	for (sum = 0; sum < MAX_CORD * 2; sum++) {
		for (x = MIN_CORD; x < MAX_CORD; x++) {
			y = sum - x;
			if (y < MIN_CORD || y > MAX_CORD) continue;
			if (f(x, y) == 0) continue;

			for (i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < MIN_CORD || nx > MAX_CORD
					|| ny < MIN_CORD || ny > MAX_CORD) continue;
				add(f(nx, ny), f(x, y));
			}
		}
	}
}

long long query(int x, int y, int x1, int y1) {
	return f(x1 - x, y1 - y);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("knight.inp", "r", stdin);
	freopen("knight.out", "w", stdout);

	initF();

	int t; cin >> t;
	int x, y, x1, y1;
	while (t--) {
		scanf("%d%d%d%d", &x, &y, &x1, &y1);
		printf("%lld \n", query(x, y, x1, y1));
		// cin >> x >> y >> x1 >> y1;
		// cout << f(x1-x, y1-y) << '\n';
	}

	return 0;
}