#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

struct task {
	i64 t,w;
	bool is_key;

	struct cmp {
		bool operator()(const task &x, const task &y) {
			if(x.is_key == y.is_key) {
				return x.w > y.w;
			}
			return x.is_key > y.is_key;
		}
	};

};


int main() {
	i64 N;
	cin >> N;
	vector<task> a(N);
	for(int i = 0; i < N; i++) cin >> a[i].t >> a[i].w >> a[i].is_key;
	sort(a.begin(), a.end(), [](const task& x, const task& y){
		return x.t < y.t;
	});

	priority_queue<task, vector<task>, task::cmp> pq;
	for(int i = 0; i < N; i++) {
		pq.push(a[i]);
		if(pq.size() > a[i].t) {
			pq.pop();
		}
	}

	i64 ans = 0, cnt = 0;
	
	while (!pq.empty()) {
		auto[t, w, key] = pq.top();
		pq.pop();
		ans += w; if(key) cnt++;
	}

	cout << cnt << ' ' << ans;
	
	

}