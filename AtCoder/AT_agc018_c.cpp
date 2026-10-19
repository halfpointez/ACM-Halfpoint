    #include <bits/stdc++.h>
    using namespace std;
    using i64 = long long;
    #define endl '\n'
    int main() {
        i64 x, y, z, n = 0, ans = 0;
        cin >> x >> y >> z;
        n = x + y + z;
        vector<pair<i64, i64>> a(n + 1), b(n + 1), c(n + 1);
        priority_queue<pair<i64, i64>, vector<pair<i64, i64>>> ctoa, ctob, atob;
        vector<i64> type(1e5 + 5, 0); //1 2 3 分别对应a, b, c
        for(int i = 1; i <= n; i++) {
            i64 at, bt, ct;
            cin >> at >> bt >> ct;
            a[i] = {at, i}, b[i] = {bt, i}, c[i] = {ct, i};
            ctoa.push({at - ct, i}); ctob.push({bt - ct, i}); atob.push({bt - at, i});
        }
        for(int i = 1; i <= n; i++) {
            auto[val, id] = c[i];
            ans += val;
            type[i] = 3;
        }
        for(int i = 1; i <= x; i++) {
        auto[val, id] = ctoa.top();
        ctoa.pop();
        ans += val;
        type[id] = 1; 
        }
        for(int i = 1; i <= y; i++) {
            while (!ctob.empty() && type[ctob.top().second] != 3) ctob.pop();
            while (!atob.empty() && type[atob.top().second] != 1) atob.pop();
            while (!ctoa.empty() && type[ctoa.top().second] != 3) ctoa.pop();
            i64 val1 = -1e18, val2 = -1e18, val3 = -1e18, id1 = 0, id2 = 0, id3 = 0;
            if(!ctoa.empty() && !atob.empty()) {
                tie(val2, id2) = ctoa.top();
                tie(val3, id3) = atob.top();
            }
            if(!ctob.empty()) {
                tie(val1, id1) = ctob.top();
            }
            if(val1 > val2 + val3) {
                ctob.pop();
                ans += val1;
                type[id1] = 2;
            } else if(val1 <= val2 + val3){
                ctoa.pop();
                atob.pop();
                ans += (val2 + val3);
                atob.push({b[id2].first - a[id2].first, id2});
                type[id2] = 1;
                type[id3] = 2;
            }
        }
        cout << ans;
    }