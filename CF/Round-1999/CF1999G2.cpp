#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 n;
#define endl '\n'
vector<i64> small, large; //存原数组下标

void ask(i64 i, i64 j) {
	cout << "? " << i << ' ' << j << endl;
	char c;
	cin >> c;
	if(c == '<') {
		small.push_back(i);
		large.push_back(j);
		return;
	}
	if(c == '>') {
		large.push_back(i);
		small.push_back(j);
		return;
	}
	if(c == '=') {
		small.push_back(i);
		return;
	}
}

void ans() {
	i64 MIN = small[0], MAX = large[0];
	for(int i = 1; i < small.size(); i++) {
		cout << "? " << MIN << ' ' << small[i] << endl;
		char c;
		cin >> c;
		if(c == '<') {
			continue;
		}
		if(c == '>') {
			MIN = small[i];
			continue;
		}
		if(c == '=') {
			continue;
		}
	}

	for(int i = 1; i < large.size(); i++) {
		cout << "? " << MAX << ' ' << large[i] << endl;
		char c;
		cin >> c;
		if(c == '<') {
			MAX = large[i];
			continue;
		}
		if(c == '>') {
			continue;
		}
		if(c == '=') {
			continue;
		}
	}
	cout << "! " << MIN << ' ' << MAX << endl;
}

void solve() {

	cin >> n;
	if(n == 1) {
		cout << '!' << ' ' << 1 << ' ' << 1 << endl;
		return;
	}
	small.clear(); large.clear();

	if(n & 1) {
		for(int i = 1; i <= n; i += 2) {
			i64 a, b; 
			a = i, b = i + 1;
			ask(a, b);
		}
		large.push_back(n);
		small.push_back(n);

	} else {
		for(int i = 1; i <= n; i += 2) {
			i64 a, b; 
			a = i, b = i + 1;
			ask(a, b);
		}
	}

	ans();
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
}