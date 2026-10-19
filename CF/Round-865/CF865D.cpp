#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 N, ans = 0;
    cin >> N;
    priority_queue<i64, vector<i64>, greater<i64>> pq;
    for (int i = 0; i < N; i++) {
        i64 p;
        cin >> p;
        pq.push(p);
        if (pq.top() < p) {
            ans += p - pq.top();
            pq.pop();
			pq.push(p);
        } 
    }
    cout << ans;
    return 0;
}