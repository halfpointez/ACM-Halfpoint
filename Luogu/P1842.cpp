#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
bool cmp(pair<i64, i64> &a, pair<i64, i64> &b) {
	auto[w1, s1] = a; auto[w2, s2] = b;
	return w2 - s1 < w1 - s2;
}

int main() {
	int N;
	cin >> N;
	vector<pair<i64, i64>> cow(N);
	vector<i64> back(N);
	for(auto &[w,s]:cow) cin >> w >> s;
	sort(cow.begin(), cow.end(), cmp);
	for(int i = N - 1; i >= 0; i--) {
		if(i == N - 1) back[i] = cow[i].first;
		else back[i] = cow[i].first + back[i + 1];
	}

	i64 ans = -1e9;
	for(int i = 0; i < N - 1; i++) {
		ans = max(back[i + 1] - cow[i].second, ans);
	}
	ans = max(-cow[N - 1].second, ans);
	cout << ans;


}