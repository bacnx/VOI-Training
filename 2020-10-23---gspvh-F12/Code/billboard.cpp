#include <bits/stdc++.h>
using namespace std;
 
#define maxN 30
#define INF 1000
 
int m, n;
int stt[maxN], s[maxN]; // lưu trạng thái ban đầu của các ô
 
// đếm số lượng bit 1 của x 
int cntBit(int x) {
	int ans = 0;
	while (x != 0) {
		if (x & 1) ans++;
		x = (x >> 1);
	}
	return ans;
}
 
/* trả về số lần ấn để cả bảng thành màu trắng khi chọn cách ấn press ở hàng đầu tiên
nếu bảng không thành màu trắng hết thì trả về vô cùng */
int solve(int press) {
	for (int i = 1; i <= m; i++) s[i] = stt[i]; // khởi tạo lại mảng s
	int ans = 0;
 
	for (int i = 1; i <= m; i++) {
		s[i-1] ^= press;
		s[i+1] ^= press;
		s[i] ^= press ^ (press << 1) ^ (press >> 1);
		s[i] &= (1<<n)-1;
 
		ans += cntBit(press);
		press = s[i];
	}
 
	return s[m] == 0 ? ans : INF;
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("billboard.inp", "r", stdin);
	freopen("billboard.out", "w", stdout);
 
	cin >> m >> n;
	for (int i = 1; i <= m; i++) for (int j = 0; j < n; j++) {
		char c; cin >> c;
		if (c == 'X') // đánh dấu tất cả các ô màu đen(X) là 1
			stt[i] |= (1<<j);
	}
 
	int ans = INF;
	for (int i = 0; i < (1<<n); i++)
		ans = min(ans, solve(i));
 
	if (ans != INF) cout << "You have to tap " << ans << " tiles.";
	else cout << "Damaged billboard.";
 
	return 0;
}