#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void merge_sort(int l, int r, vector<i64> &a, vector<i64> &tmp) {
	if(l >= r) return; //避免空区间和奇怪的东西所以加
	i64 mid = l + ((r - l) >> 1);

	i64 i = l, j = mid + 1, k = l;

	merge_sort(l, mid, a, tmp);
	merge_sort(mid + 1, r, a, tmp);
	if(a[mid] <= a[mid + 1]) return; //优化
	
	while (i <= mid && j <= r) {
		if(a[i] <= a[j]) {
			tmp[k++] = a[i++];
		} else {
			tmp[k++] = a[j++];
		}
	}

	while (i <= mid) {
		tmp[k++] = a[i++];	
	}

	while (j <= r) {
		tmp[k++] = a[j++];
	}

	for(int p = l; p <= r; p++) {
		a[p] = tmp[p];
	}
	
	
}

int main() {
	int n;
	cin >> n;
	vector<i64> a(n);
	vector<i64> tmp(n);
	for (auto &i:a) cin >> i; 
	merge_sort(0, a.size() - 1, a, tmp);
	for(auto &i:a) cout << i << ' ';
}