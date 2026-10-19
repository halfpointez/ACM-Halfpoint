#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int OFFSET = 5000;
const int MAXJ = 2 * OFFSET;  // 10000

int main() {
    int n;
    cin >> n;

    // dp[i][j]：前 i 张牌，总差值为 (j - OFFSET) 的最少翻转次数
    vector<vector<int>> dp(n + 1, vector<int>(MAXJ + 1, INF));
    dp[0][OFFSET] = 0;  // 0 张牌，差值 0，翻转 0 次

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        int diff1 = a - b;   // 不翻转
        int diff2 = b - a;   // 翻转

        for (int j = 0; j <= MAXJ; j++) {
            // 不翻转
            int prev = j - diff1;
            if (prev >= 0 && prev <= MAXJ && dp[i-1][prev] != INF) {
                dp[i][j] = min(dp[i][j], dp[i-1][prev]);
            }
            // 翻转
            prev = j - diff2;
            if (prev >= 0 && prev <= MAXJ && dp[i-1][prev] != INF) {
                dp[i][j] = min(dp[i][j], dp[i-1][prev] + 1);
            }
        }
    }

    // 从差值 0 向两边找第一个可达的
    for (int d = 0; d <= OFFSET; d++) {
        if (dp[n][OFFSET + d] != INF) {
            cout << dp[n][OFFSET + d] << endl;
            break;
        }
        if (dp[n][OFFSET - d] != INF) {
            cout << dp[n][OFFSET - d] << endl;
            break;
        }
    }

    return 0;
}