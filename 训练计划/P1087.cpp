#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<char> Node;


i64 qpow(i64 a, i64 b) {
	i64 res = 1;
	while (b) {
		if(b & 1) res *= a;
		b >>= 1;
		a *= a;
	}
	return res;
}

void build_tree(i64 u, string s) {
	
	i64 l = 2 * u, r = 2 * u + 1;
	bool cnt0 = 0, cnt1 = 0;
	for(auto &i:s) {
		if(i == '0') cnt0 = 1;
		if(i == '1') cnt1 = 1;
	}
	if(cnt0 && cnt1) Node[u] = 'F';
	else if(cnt0 && cnt1 == 0) Node[u] = 'B';
	else if(cnt0 == 0 && cnt1) Node[u] = 'I';
	if(s.size() == 1) return;
	string sl = s.substr(0, s.size() / 2);
	string sr = s.substr(s.size() / 2, s.size() / 2);
	build_tree(l, sl); build_tree(r, sr);
}

void dfs(i64 u) {
	if(Node[u] == '0') return;
	i64 l = 2 * u, r = 2 * u + 1;
	dfs(l), dfs(r);
	cout << Node[u]; 
}

int main() {
	i64 N;
	cin >> N;
	string s;
	cin >> s;
	N = qpow(2, N);
	N *= 4;
	Node.resize(N + 1, '0');
	build_tree(1, s);
	dfs(1);


}