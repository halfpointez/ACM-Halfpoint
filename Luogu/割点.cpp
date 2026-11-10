#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for(auto &i:a) cin >> i;
	stack<int> st;
	i64 ans;
	for(int i = 0; i < n; i++) {
		i64 tmp = 0;
		while (!st.empty() && a[i] > st.top()) {
			
		}

	}
	cout << ans << endl;
}