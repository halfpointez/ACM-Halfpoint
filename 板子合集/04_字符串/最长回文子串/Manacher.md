# Manacher(马拉车)

> 所属分类: 字符串 › 最长回文子串
> 复杂度: O(n)

## 适用问题
- 线性时间求最长回文子串长度
- 回文半径(以每个位置为中心的最长回文)

### 用法
用于在线性时间 $\mathcal{O}(n)$ 内求解字符串的最长回文子串长度。

### 实现步骤
1. 预处理字符串：插入 `#` 统一奇偶回文
2. 维护 `maxr`、`mid`、`ans`
3. 遍历中心，利用对称性扩展回文半径

### 完整模板
```cpp
#include <bits/stdc++.h>
using namespace std;
string change(string &s) {
	string temp = "!#";
	for(auto &c:s) {
		temp += c;
		temp += '#';
	}
	temp += "^";
	return temp;
}

int manacher(string &s) {
	int maxr = 0, mid = 0, ans = 0;
	vector<int> p(s.size(), 0);
	for(int i = 0; i < s.size(); i++) {
		if(maxr >= i) {
			p[i] = min(p[2 * mid - i], maxr - i);
		}
		while(s[i - p[i] - 1] == s[i + p[i] + 1])
		p[i]++;
		if(i + p[i] > maxr) {
			mid = i;
			maxr = i + p[i];
		}
		ans = max(ans, p[i]);
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	s = change(s);
	cout << manacher(s);
}
```
