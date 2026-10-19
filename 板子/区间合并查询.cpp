#include <bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using namespace std;

vector<pair<i64, i64>> merge_seg(vector<pair<i64, i64>> &seg) { //合并并且返回合并好的区间数组
	vector<pair<i64, i64>> res;
	if(seg.empty()) {
		return res;
	}
	sort(seg.begin(), seg.end()); // 按 l 排序, l 相同按 r

	i64 L = seg[0].first, R = seg[0].second;
	for(auto &i:seg) {
		auto[l, r] = i;
		if(l > R + 1) { // 如果是如果题意是“区间覆盖连续整数”（如 [1,2] 和 [3,4] 算连通），把 if (l > R) 改成 if (l > R + 1) 即可。
			res.push_back({L, R});
			L = l, R = r;
		} else {
			R = max(r, R);
		}
	}
	res.push_back({L, R});
	return res;
}

pair<i64, i64> get_edge(i64 k, vector<pair<i64, i64>> &fin_seg) {//输入k 返回第k个合并区间的左右边界
	return {fin_seg[k - 1].first, fin_seg[k - 1].second};
}

pair<i64, i64> get_pos(i64 x, vector<pair<i64, i64>> &fin_seg) { //查询下标 x属于哪个合并区间 以及在该区间内的偏移量(第几位)
	vector<i64> seg_L;//若要多次查询 可以把这个的初始化放在外面 优化时间
	for(auto &i:fin_seg) {
		seg_L.push_back(i.first);
	}
	i64 idx = upper_bound(seg_L.begin(), seg_L.end(), x) - seg_L.begin() - 1; // 找到第一个 左端点 > x 的位置
	if(idx < 0 || idx >= fin_seg.size()) return {-1, -1};
	if(x > fin_seg[idx].second) return {-1, -1};
	return {idx, x - fin_seg[idx].first};//区间 相对位置
}

int main() {
	int N;
	cin >> N;
	vector<pair<i64, i64>> seg(N); //原始区间 记录l, r
	for(auto &i:seg) {
		cin >> i.first >> i.second;
	}
	vector<pair<i64, i64>> fin_seg = merge_seg(seg);
	i64 ans = 0;
	for(auto i:fin_seg) {
		ans += i.second - i.first + 1;
	}
	cout << ans;

}

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 在线维护：初始位置在 x，顺序读取 m 个区间
void solve() {
    i64 n, x, m;
    cin >> n >> x >> m;
    
    i64 L = x, R = x; // 初始可达范围只有一个点
    
    for (int i = 0; i < m; i++) {
        i64 l, r;
        cin >> l >> r;
        
        // 关键判断：两个闭区间 [L,R] 和 [l,r] 是否有交集
        // 有交集的条件：l <= R && L <= r
        if (l <= R && L <= r) {
            L = min(L, l); // 左边界只能向左扩
            R = max(R, r); // 右边界只能向右扩
        }
    }
    
    cout << R - L + 1 << '\n'; // 输出最终可达区间长度
}
