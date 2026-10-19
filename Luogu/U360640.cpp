#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const i64 MOD = 1e9 + 7;
i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	while (b) {
		if(b & 1LL) res *= a;
		res %= MOD;
		a *= a;
		a %= MOD;
		b >>= 1;
	}
	return res;
	
}
int main() {
	int n;
	cin >> n;
	
	cout << sum;
}