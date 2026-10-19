#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
	int n;
	cin >> n;
	stack<i64> S;
	vector<i64> h(n);
	i64 ans = 0;
	for(auto &i:h) cin >> i;
	for(int i = 0; i < n; i++) {
		if(h[i] >= S.top()) {
			while (!S.empty() && S.top() <= h[i]) {
				i64 cur = S.top();
				S.pop();
				if(S.empty()) break;
				ans += 
			}
		}
		
		
		S.push(i);
		
	}
	
}