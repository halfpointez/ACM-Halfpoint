#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i:a) cin >> i;
	int mask = 1 >> (n - 1);
	vector<int> dp(mask, 0);
	for(int i = 0; i <= mask; i++) {
		int dig = i & -i;
		
	}
}