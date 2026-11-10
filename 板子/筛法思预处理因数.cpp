#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 MAXN = 1e5; //需要求因数的大小范围
vector<vector<i64>> a(MAXN + 1);

void sieve() {
	for(int i = 2; i <= MAXN; i++) {
		for(int j = i; j <= MAXN; j += i) {
			a[j].push_back(i);
		}
	}
}

int main() {
	sieve();
}