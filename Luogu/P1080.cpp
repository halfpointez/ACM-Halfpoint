#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

struct Person { i64 l, r; };

bool cmp(const Person &a, const Person &b) {
    return a.l * a.r < b.l * b.r;   // a*b 升序
}

// ============ 高精度（基 10^9，低位在前）============
const i64 BASE = 1e9;

void mul(vector<i64> &a, i64 b) {
    i64 carry = 0;
    for (size_t i = 0; i < a.size(); i++) {
        i64 cur = a[i] * b + carry;
        a[i] = cur % BASE;
        carry = cur / BASE;
    }
    while (carry) {
        a.push_back(carry % BASE);
        carry /= BASE;
    }
}

vector<i64> div(const vector<i64> &a, i64 b) {
    vector<i64> res(a.size());
    i64 rem = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        i64 cur = rem * BASE + a[i];
        res[i] = cur / b;
        rem = cur % b;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

bool lessThan(const vector<i64> &a, const vector<i64> &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

void print(const vector<i64> &a) {
    printf("%lld", a.back());
    for (int i = (int)a.size() - 2; i >= 0; i--)
        printf("%09lld", a[i]);
    puts("");
}

int main() {
    int n;
    scanf("%d", &n);
    i64 kl, kr;
    scanf("%lld %lld", &kl, &kr);

    vector<Person> p(n);
    for (auto &x : p) scanf("%lld %lld", &x.l, &x.r);

    sort(p.begin(), p.end(), cmp);

    vector<i64> cur = {1};
    mul(cur, kl);                    // cur = 国王的左手数字

    vector<i64> best = {0};

    for (auto &x : p) {
        vector<i64> cand = div(cur, x.r);   // 当前大臣的奖赏
        if (lessThan(best, cand)) best = cand;
        mul(cur, x.l);                       // 更新前缀乘积
    }

    print(best);
    return 0;
}