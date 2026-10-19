#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        i64 ans = 0;
        int y = r; 
        for (int x = 1; x <= r; x++) { 

            while (x * x + y * y >= (r + 1) * (r + 1)) {
                y--;
            }
			int ytmp = y;

            while (ytmp > 0 && x * x + ytmp * ytmp >= r * r) {
                ans++; 
                ytmp--;
            }
  
        }

	
        cout << ans * 4 + 4 << '\n';
    }
    return 0;
}