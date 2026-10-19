# ST表(倍增)

> 所属分类: 数据结构 › 静态区间RMQ
> 复杂度: 预处理 O(n log n) / 查询 O(1)

## 适用问题
- 静态可重复贡献 RMQ: MAX、MIN、GCD、LCM、按位或、按位与

## 核心思想
ST表运用了倍增的思想: 先维护每个位置从 2^0 到 2^n(小于最后位置)长度中的RMQ。
例子: 数组 1 2 3 4 5 6 7 8, 查询 2-6 只需 2-4 和 4-6 合并。

```cpp
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 n;
vector<i64> logN;
vector<i64> arr;
vector<vector<i64>> st; //修复: 原为 st(100, vector<i64>(100)) 硬编码

void pre() {
	logN[2] = 1;
	for(i64 i = 3; i <= n; i++) { //修复: 原为 i < n, logN[n] 未初始化
		logN[i] = logN[i / 2] + 1;
	}
}

void init() {
	st.assign(n, vector<i64>(logN[n] + 1)); //修复: 动态分配
	for(i64 i = 0; i < n; i++) st[i][0] = arr[i];
	for(i64 i = 1; i <= logN[n]; i++) {
		for(i64 j = 0; j + (1 << i) <= n; j++) {
			st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		}
	}
}

i64 query(i64 l, i64 r) { //0-based, l <= r
	i64 k = logN[r - l + 1]; //修复: 原为 l - r + 1, 下标为负越界
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() { //修复: 原 main 只读入 n 未做任何事, 补全
	cin >> n;
	arr.resize(n + 1);
	logN.resize(n + 1);
	for(i64 i = 0; i < n; i++) cin >> arr[i];
	pre();
	init();
	i64 l, r;
	cin >> l >> r;
	cout << query(l, r) << endl;
}
```

## 注意
- 静态数据结构, 不支持修改;需要修改用线段树
