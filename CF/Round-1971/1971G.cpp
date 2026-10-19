#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n), ans(n);
        map<int, vector<int>> pos, val;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int g = a[i] >> 2; 
            pos[g].push_back(i);
            val[g].push_back(a[i]);
        }

        for (auto &it : val) {
            int g = it.first;
            auto &v = it.second;

            sort(v.begin(), v.end());

            auto &p = pos[g];
            for (int j = 0; j < (int)p.size(); j++) {
                ans[p[j]] = v[j];
            }
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}