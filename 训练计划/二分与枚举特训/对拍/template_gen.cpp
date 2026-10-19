// ===== 数据生成器模板（对拍用） =====
// 用法:  ./gen 123 > in.txt      123 = 种子; 对拍脚本会自动传 1,2,3...
// 黄金法则: 小范围 + 小值域(制造重复) + 边界值(最小值/最大值/越界) + 多组不同规模
// 提醒: 必须用 argv[1] 做种子, 保证可复现 (失败案例重跑同一种子必现)
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    unsigned seed = (argc > 1) ? stoul(argv[1]) : (unsigned)time(nullptr);
    mt19937 rng(seed);

    // ---------- 改这里 ----------
    int n = int(rng() % 10) + 1;   // 先从小数据开始
    int q = int(rng() % 5) + 1;
    cout << n << ' ' << q << '\n';
    for (int i = 0; i < n; i++) cout << int(rng() % 20) << " \n"[i + 1 == n];
    for (int i = 0; i < q; i++) cout << int(rng() % 25) << " \n"[i + 1 == q];
    // ---------------------------

    return 0;
}
