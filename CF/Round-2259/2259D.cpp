#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt0 = 0;
    vector<int> zero_pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            cnt0++;
            zero_pos.push_back(i);
        }
    }

    if (cnt0 == 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    string ans(n, 'C'); 
    if (cnt0 == 0) {
        if (n > 0) ans[0] = 'A';
    } else { 

        ans[zero_pos[0]] = 'A';
        ans[zero_pos[1]] = 'B';
        for (int i = 2; i < zero_pos.size(); i++) {
            ans[zero_pos[i]] = 'A';
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}