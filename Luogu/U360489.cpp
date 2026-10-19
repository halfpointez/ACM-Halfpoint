#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;

i64 ksm(i64 a,i64 b) {
	i64 res = 1;
	while (b) {
		if(b & 1LL) res *= a;
		a *= a;
		b >>= 1LL;
	}
	return res;
}

int main() {
	i64 n;
	cin >> n;
	vector<i64> a(n + 1);
	vector<i64> pre(n + 1);
	pre[0] = 0;
	a[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = a[i] ^ pre[i - 1];
	}
	vector<i64> cnt0(32, 0), cnt1(32, 0);

	for(int i = 0; i <= n; i++) {
		i64 cnt = 0;
		while (cnt <= 31) {
			if(pre[i] & (1LL << cnt)) cnt1[cnt]++;
			else cnt0[cnt]++;
			cnt++;
		}
	}
	i64 ans = 0;
	for(int i = 0; i <= 31; i++) {
		ans += cnt0[i] * cnt1[i] * ksm(2, i);
	}
	cout << ans << endl;

	

}