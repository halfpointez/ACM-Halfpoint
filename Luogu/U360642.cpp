#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const i64 MOD = 1e9 + 7;

i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	while (b) {
		if(b & 1) res *= a;
		a *= a;
		a %= MOD;
		b >>= 1;
		res %= MOD;
	}
	return res;
} 

int main() {
	i64 n;
	cin >> n;
	i64 or_sum = 0;
	for(int i = 0; i < n; i++) {
		i64 tmp;
		cin >> tmp;
		or_sum |= tmp;
	} //不要对按位运算取MOD
	i64 ans = 0;
	for(int i = 0; i < 32; i++) {
		if((or_sum >> i) & 1) ans += ksm(2, n - 1) * ksm(2, i);
		ans %= MOD;
	}
	cout << ans;
}