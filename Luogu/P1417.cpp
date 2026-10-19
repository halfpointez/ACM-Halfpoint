#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
struct food {
	i64 a, b, c;
};


//b[j]*c[i] - b[i]*c[j] > 0
bool cmp(const food &i, const food &j) {
	return j.b * i.c < i.b * j.c;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T, n;
	cin >> T >> n;
	vector<i64> dp(T + 1, 0);
	vector<food> Food(n);	
	for(int i = 0; i < n; i++) cin >> Food[i].a;
	for(int i = 0; i < n; i++) cin >> Food[i].b;
	for(int i = 0; i < n; i++) cin >> Food[i].c;

	sort(Food.begin(), Food.end(), cmp);
	for(int i = 0; i < n; i++) {
		for(int j = T; j >= Food[i].c; j--) {
			dp[j] = max(dp[j], dp[j - Food[i].c] + Food[i].a - Food[i].b * j);
		}
	}
	i64 ans = 0;
	for(int i = 0; i <= T; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}