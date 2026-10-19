测试点信息
4ms/1.08MB
WA
#1
4ms/788.00KB
WA
#2
4ms/788.00KB
WA
#3
4ms/788.00KB
AC
#4
4ms/1.09MB
AC
#5
4ms/788.00KB
WA
#6
4ms/788.00KB
AC
#7
4ms/788.00KB
WA
#8
5ms/1.04MB
AC
#9
4ms/788.00KB
AC
#10
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const i64 MOD = 1e9 + 7;


int main() {
	int N, V;
	cin >> N >> V;
	vector<i64> v(N + 1, 0), w(N + 1, 0);

	for(int i = 1; i <= N; i++) {
		cin >> v[i] >> w[i];
	}

	vector<i64> dp(V + 1, 0); //当背包容量为V时候能得的最大价值
	vector<i64> cnt(V + 1, 1); //当背包容量为V时候能得的最大价值的方案数

	for(int i = 1; i <= N; i++) {
		for(int j = V; j >= v[i]; j--) {
			i64 take = dp[j - v[i]] + w[i], n_take = dp[j];
			if(take > n_take) {
				dp[j] = take;
				cnt[j] = cnt[j - v[i]];
			} else if(take == n_take) cnt[j] = (cnt[j - v[i]] + cnt[j]) % MOD;
		}
	}

	cout << cnt[V];

	


}



测试点信息
4ms/788.00KB
AC
#1
4ms/788.00KB
AC
#2
4ms/788.00KB
AC
#3
5ms/1008.00KB
AC
#4
4ms/788.00KB
AC
#5
4ms/788.00KB
AC
#6
5ms/788.00KB
AC
#7
4ms/788.00KB
AC
#8
4ms/788.00KB
AC
#9
4ms/788.00KB
AC
#10

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, V;
    cin >> N >> V;

    vector<i64> dp(V + 1, 0);
    vector<i64> cnt(V + 1, 1);

    for (int i = 1; i <= N; i++) {
        int v, w;
        cin >> v >> w;

        for (int j = V; j >= v; j--) {
            i64 take = dp[j - v] + w;
            i64 not_take = dp[j];

            if (take > not_take) {
                dp[j] = take;
                cnt[j] = cnt[j - v];
            } else if (take == not_take) {
                cnt[j] = (cnt[j] + cnt[j - v]) % MOD;
            }
        }
    }

    cout << cnt[V] << '\n';
    return 0;
}
