#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    long long ans = 0;
    long long rem = sum;

    // sum 最大 10^18，60 位足够
    for (int bit = 60; bit >= 0; --bit) {
        long long val = 1LL << bit;
        if (val > rem) {
            // 这一位肯定可以不放 1
            continue;
        }

        // 判断：如果这一位不放 1，低位最多能表示 n * (val - 1)
        // 即 rem <= n * (val - 1) 是否成立
        // 用向上取整避免溢出：rem / n 向上取整 <= val - 1
        long long need = (rem + n - 1) / n; // ceil(rem / n)
        if (need <= val - 1) {
            // 可以不放 1
            continue;
        }

        // 必须放 1
        long long x = min((long long)n, rem / val);
        ans |= val;
        rem -= x * val;
    }

    cout << ans << '\n';
    return 0;
}