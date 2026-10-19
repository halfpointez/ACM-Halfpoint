#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int MAX = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		int in, out;
		cin >> out >> in;
		sum -= out;
		sum += in;
		MAX = max(MAX, sum);
	}
	cout << MAX;
}