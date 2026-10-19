#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    map<int, bool> mp; // 记录要删去的位置
    stack<int> S;

    for (int i = 0; i < s.size(); i++) {
        while (!S.empty()) {
            if (k == 0) break;
            if (s[S.top()] - '0' > s[i] - '0') {
                mp[S.top()] = 1;
                S.pop();
                k--;
            } else break;
        }
        S.push(i);
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        if (k == 0) break;
        if (!mp[i]) {
            mp[i] = 1;
            k--;
        }
    }

    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (!mp[i]) ans.push_back(s[i]);
    }

    int pos = 0;
    while (pos < (int)ans.size() && ans[pos] == '0') {
        pos++;
    }

    if (pos == (int)ans.size()) {
        cout << 0 << endl;
    } else {
        cout << ans.substr(pos) << endl;
    }

    return 0;
}