#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	i64 n;
	cin >> n;
	vector<i64> L(n + 1);
	vector<i64> R(n + 1);
	vector<i64> d(n + 1);

	for(int i = 1; i <= n; i++) {
		cin >> L[i] >> R[i];	
	}
	for(int i = 1; i < n; i++) cin >> d[i];
	i64 mn = L[1], mx = R[1];
	for(int i = 2; i <= n; i++) {
		i64 Ltmp = max(L[i], mn - d[i - 1]), Rtmp = min(R[i], mx + d[i - 1]);
		if(Ltmp > Rtmp) {
			cout << "NO" << endl;
			return 0;
		}
		mx = Rtmp, mn = Ltmp;
	}
	cout << "YES" << endl;

}