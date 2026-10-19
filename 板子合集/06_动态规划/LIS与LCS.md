# LIS与LCS

> 所属分类: 动态规划 › 线性DP
> 复杂度: LIS O(n²) / O(n log n), LCS O(nm)
> 备注: 2026-10-18 初稿, 待你核对

## 适用问题
- LIS(最长上升子序列): 单个序列内的最长上升子序列长度
- LCS(最长公共子序列): 两个序列的最长公共子序列长度(相似度/匹配类)
- 两节均只收录求长度的模板

## LIS(最长上升子序列)

n 较小时 O(n²) DP 直观; n 较大时用贪心 + 二分。

### O(n²) DP(以 i 结尾)

- `dp[i]` 表示以 `a[i]` 结尾的最长上升子序列长度; 答案取所有 `dp[i]` 的最大值
- 转移: 枚举前驱 `j < i` 且 `a[j] < a[i]`, `dp[i] = max(dp[i], dp[j] + 1)`
- 复杂度: O(n²) 时间, O(n) 空间

```cpp
int LIS_n2(const vector<int> &a) {
    int n = (int)a.size(), ans = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    return ans;
}
```

### O(n log n)(贪心 + 二分)

- 维护 `tails[k]`: 所有长度为 `k + 1` 的上升子序列中, 最小的结尾值(它单调不减)
- 每个 `a[i]` 在 `tails` 里二分找第一个可替换的位置: 接在末尾或替换; `tails` 的长度即答案
- 复杂度: O(n log n) 时间, O(n) 空间

```cpp
int LIS_nlogn(const vector<int> &a) {
    vector<int> tails;                                        // tails[k]: 长度 k+1 的最小结尾
    for (int x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x); // 严格上升: 第一个 >= x
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}
```

一句话区分: 求**严格上升**用 `lower_bound`(找第一个 `>= x`, 相等会顶掉); 求**非严格上升**(不下降)改用 `upper_bound`(找第一个 `> x`, 相等保留), 两段只差这一处(O(n²) 版对应把 `a[j] < a[i]` 改成 `a[j] <= a[i]`)。

- 对应题目: P1020 导弹拦截(第一问不上升用 `upper_bound`、第二问上升用 `lower_bound`)、LeetCode 300 最长递增子序列
- 注意: 求最长**不升**子序列时 `tails` 是降序, 需要 `upper_bound(tails.begin(), tails.end(), x, greater<int>())`。

## LCS(最长公共子序列)

- `dp[i][j]` 表示 `a` 的前 `i` 个与 `b` 的前 `j` 个的最长公共子序列长度
- 转移: `a[i - 1] == b[j - 1]` 时 `dp[i][j] = dp[i - 1][j - 1] + 1`(该字符直接接上); 否则 `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`(两个末尾字符配不上, 至少丢掉一个)
- 复杂度: O(nm) 时间, O(nm) 空间

```cpp
int LCS(const string &a, const string &b) {
    int n = (int)a.size(), m = (int)b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][m];
}
```

提点: 字母表小、串长很大时可用 bitset 把 O(nm) 压位优化(约 O(nm/64)), 本板子不展开。

- 对应题目: AcWing 897 最长公共子序列、LeetCode 1143 最长公共子序列
