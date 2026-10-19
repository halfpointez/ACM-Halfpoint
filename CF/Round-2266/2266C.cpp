#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool zero = 0, one = 0;
    i64 pos_1 = -1;
    i64 pos_2 = -1;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            if(s[i] == '1') {
                one = 1;
            } else {
                zero = 1;
            }
        } 
        if(i != 0) {
            if(s[i] < s[i - 1]) {
                pos_1 = i;
                break;
            }
        }
    }

    if(pos_1 == -1) {
        cout << 0 << endl;
        return;
    } 

    for(int i = n - 1; i >= 0; i--) {
        if(i != 0) {
            if(s[i - 1] > s[i]) {
                pos_2 = i;
                break;
            }
        }
    }


    i64 ans1 = 0;
    for(int i = pos_1; i < n; i++) {
        if(s[i] == '0') ans1++;  
    }

    if(zero == 0) {  
        cout << ans1 << endl;
        return;
    }

    int total0 = 0;
    for(char c : s) if(c == '0') total0++;
    int ans = total0;         
    int pref1 = 0;
    int suf0 = total0;
    for(int k = 1; k <= n; k++) {
        if(s[k - 1] == '1') pref1++;
        else suf0--;
        ans = min(ans, pref1 + suf0);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }	
}