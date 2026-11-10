#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
string front, mid, back;

void dfs(string m, string b) {
	if(m.empty()) return;
	char root = b.back();
	front.push_back(root);
	i64 k = m.find(root);
	dfs(m.substr(0, k), b.substr(0, k));
	dfs(m.substr(k + 1), b.substr(k, b.size() - 1 - k));
}

int main() {
	cin >> mid >> back;
	dfs(mid, back);
	cout << front;
}