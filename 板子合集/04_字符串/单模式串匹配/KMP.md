# KMP

> 所属分类: 字符串 › 单模式串匹配
> 复杂度: O(n + m)

## 适用问题
- 在主串中查找模式串的所有出现位置(单模式匹配)

### 用法
用于单模式串匹配，可在主串中快速查找模式串的所有出现位置，避免暴力匹配的回溯，时间复杂度 $\mathcal{O}(n+m)$。

### 实现步骤
对于一串字符串 如
匹配串: abcdabxa...
模式串: abcdabcy

可以发现 abcdab是匹配的
且abcdab的最长前后缀存在为ab
因为前面都匹配 只有从c-x不匹配
所以x前的肯定是ab
那就意味着可以从c-x开始比较 而不用从头开始遍历

### 完整模板
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s1;
	string s2;
	cin >> s1 >> s2;
	int s2_len = s2.size();
	int s1_len = s1.size();
	vector<int> next(s2_len, 0);
	int i = 0, j = 1;
	while(i < s2_len && j < s2_len) {
		while (i > 0 && s2[i] != s2[j]) {
			i = next[i - 1];
		}
		if(s2[i] == s2[j]) i++;
		next[j] = i;
		j++;
	}
	i = 0;
	j = 0;
	while (j < s1_len) {
		while(i > 0 && s2[i] != s1[j]) {
			i = next[i - 1];
		}
		if(s2[i] == s1[j]) {
			i++;
		}
		if(i == s2_len) {
			cout << j - i + 2 << endl;
			i = next[i - 1]; //修复: 回退以继续找重叠匹配
		}
		j++;
	}
	for(auto &i:next) {
		cout << i << ' ';
	}
}
```
