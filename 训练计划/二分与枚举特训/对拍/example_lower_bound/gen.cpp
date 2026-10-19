// 生成: n <= 15 的升序数组(值域 0..30, 制造大量重复), q <= 8 次询问(含越界值)
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    unsigned seed = (argc > 1) ? stoul(argv[1]) : (unsigned)time(nullptr);
    mt19937 rng(seed);

    int n = int(rng() % 15) + 1;
    int q = int(rng() % 8) + 1;

    vector<int> a(n);
    for (auto& x : a) x = int(rng() % 31); // 0..30 小值域 → 重复多 → 逼边界
    sort(a.begin(), a.end());

    cout << n << ' ' << q << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
    for (int i = 0; i < q; i++) {
        int x = int(rng() % 40); // 0..39, 会问到 >30 的越界
        cout << x << " \n"[i + 1 == q];
    }
    return 0;
}
