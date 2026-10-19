#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

bool check(i64 mid, vector<i64> &a, i64 x, i64 k) {
    i64 len = 0;
    i64 l = -1, r = -1;
    vector<pair<i64, i64>> M;
    for(auto &i:a) {
		
        i64 l_tmp = max<i64>(0, (i - mid + 1)), r_tmp = min<i64>(x, i + mid - 1); 
		if (l_tmp > r_tmp) continue;
        if(l == -1) {
            l = l_tmp, r = r_tmp;
        } else if(l_tmp <= r + 1) {
            r = max(r, r_tmp);
        } else {
            M.push_back({l, r});
            l = l_tmp, r = r_tmp;
        }
    }
    if(l != -1) M.push_back({l, r});
    for(auto &i:M) {
        len += i.second - i.first + 1;
    }
    if(x + 1 - len >= k) {
        return 1;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        i64 n, k, x;
        cin >> n >> k >> x;
        vector<i64> a(n);
        for(auto &i:a) {
            cin >> i;
        }

        sort(a.begin(), a.end());
        i64 l = 0, r = x;
        while (l < r) {
            i64 mid = l + ((r - l + 1) >> 1);
            if(check(mid, a, x, k)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        i64 mid = l;
        l = -1, r = -1;
        vector<pair<i64, i64>> M;

        for(auto &i:a) {
            i64 l_tmp = max<i64>(0, (i - mid + 1)), r_tmp = min<i64>(x, i + mid - 1); 
			if (l_tmp > r_tmp) continue;
            if(l == -1) {
                l = l_tmp, r = r_tmp;
            } else if(l_tmp <= r + 1) {
                r = max(r, r_tmp);
            }   else  {
                M.push_back({l, r});
                l = l_tmp, r = r_tmp;
            }
        }     
		if(l != -1) M.push_back({l, r});

        vector<i64> ans;
        i64 pos = 0;
        for(auto [L, R] : M) {
            if(pos < L) {
                i64 take = min(k, L - pos);
                for(i64 i = 0; i < take; i++) ans.push_back(pos + i);
                k -= take;
                if(k == 0) break;
            } pos = R + 1;
        }

        while (k--) {
            ans.push_back(pos);
            pos++;
        }
            
        for(auto &i:ans) cout << i << ' ';
        cout << endl;
        
        

        }
        
    }
    
