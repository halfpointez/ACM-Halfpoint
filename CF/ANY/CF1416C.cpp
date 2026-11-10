#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	i64 n;
	cin >> n;

	vector<i64> a(n + 1);
	i64 x = 0, inv = 0;
	a[0] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 31; i >= 1; i--) {
		map<i64, i64> cnt0, cnt1;
		i64 cost01 = 0, cost10 = 0;

		for(int j = 1; j <= n; j++) {
			i64 pre_word = a[j] >> i;
			i64 cur_dig =  (a[j] >> (i - 1)) & 1;
			if(cur_dig) {
				cost01 += cnt0[pre_word];
				cnt1[pre_word]++;
			} else {
				cost10 += cnt1[pre_word];
				cnt0[pre_word]++;
			}
		}


		if(cost01 >= cost10) {
			inv += cost10;
			x += 0;
		} else {
			inv += cost01;
			x |= (1 << (i - 1));
		}
	}

	cout << inv << ' ' << x;
	

}

