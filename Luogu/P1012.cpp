#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for(auto &i:arr) cin >> i;
	sort(arr.begin(), arr.end(), [](const auto &x, const auto &y){return x + y > y + x;});
	string s;
	for(int i = 0; i < arr.size(); i++) {
		s += arr[i];
	}
	cout << s;
}
