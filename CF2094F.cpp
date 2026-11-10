#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> ans(n, vector<int>(m));
		if((m % k == 0 && m >= k)) {
			if(k & 1) {
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < m; j++) {
						if(i & 1) {z
							ans[i][j] = (i * m + j) % k + 1;
						} else {
							int tmp = k - ((i * m + j) % k + 1) + 1;
							ans[i][j] = tmp;
							if(tmp == k / 2 + 1) {
								swap(ans[i][j], ans[i][j - 1]);
							}
						}
						
					}
				}
			} else {
                          for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {
                              if (i & 1) {
                                ans[i][j] = (i * m + j) % k + 1;
                              } else {
                                int tmp = k - ((i * m + j) % k + 1) + 1;
                                ans[i][j] = tmp;
                              }
                            }
                          }
                        }
		} else {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					ans[i][j] = (i * m + j) % k + 1;
				}
			}
		}

		for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	}
	
}


