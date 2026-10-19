#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, s;
	cin >> n >> s;
	int a, b, h;
	cin >> a >> b;
	h = a + b;
	vector<int> app;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if(x <= h) app.push_back(y);
	}
	int ans = 0;
	sort(app.begin(), app.end());
	for(int i = 0; i < app.size(); i++) {
		if(s - app[i] < 0) break;
		else {ans++; s -= app[i];}
	}

	cout << ans;
}