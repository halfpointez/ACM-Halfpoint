#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	int V = 1000;
	int total = 0;
	vector<bool> dp(1001, 0);
	dp[0] = 1;
	vector<int> w;
	vector<int> a(6);
	a[0] = 1, a[1] = 2, a[2] = 3, a[3] = 5, a[4] = 10 , a[5] = 20;
	for(int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		for(int j = 1; j <= n; j++) {
			w.push_back(a[i]);
		}
	}

	for(int i = 0; i < w.size(); i++) {
		for(int j = V; j >= w[i]; j--) {
			dp[j] = dp[j - w[i]] | dp[j];
		}
	}

	for(int i = 1; i <= 1000; i++) {
		if(dp[i]) total++;
	}

	cout << "Total=" << total;

	
}