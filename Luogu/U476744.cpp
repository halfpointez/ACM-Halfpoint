#include<bits/stdc++.h>                // 引入常用头文件，包含优先队列、map、排序等
using namespace std;                    // 使用标准命名空间
typedef long long ll;                   // 把 long long 简写为 ll，防止数据溢出

struct Node{                            // 定义加油站结构体
    ll x, y;                            // x 表示位置，y 表示每单位油价
} a[100005];                            // 最多 1e5 个加油站，数组开大一点

bool cmp(Node a, Node b){               // 排序比较函数
    return a.x < b.x;                   // 按加油站位置从小到大排序
}

int main(){
    ll n, G, B, D;                      // n 个加油站，G 油箱容量，B 初始油量，D 终点距离
    cin >> n >> G >> B >> D;            // 读入四个基本参数
    for(int i = 1; i <= n; i++){        // 读入每个加油站
        cin >> a[i].x >> a[i].y;        // 读入位置 x 和油价 y
    }
    sort(a + 1, a + n + 1, cmp);        // 将加油站按位置排序
    a[n + 1].x = D;                     // 把终点也当成一个特殊站点，位置为 D
    a[n + 1].y = 0;                     // 终点油价设为 0，只是占位，后面不会在终点加油

    priority_queue<ll, vector<ll>, greater<ll>> pq_mi; // 小根堆：堆顶是候选油中最便宜的价格
    priority_queue<ll> pq_mx;                          // 大根堆：堆顶是候选油中最贵的价格
    map<ll, ll> mp;                                    // mp[价格] = 这个价格当前有多少单位候选油

    mp[0] = B;                          // 初始有 B 单位油，看成价格为 0 的油
    pq_mi.push(0);                      // 把价格 0 放入小根堆
    pq_mx.push(0);                      // 把价格 0 放入大根堆
    ll t = B;                           // t 表示当前候选油总量
    ll ans = 0;                         // ans 记录真正消耗掉的油的总花费
    ll p = 0;                           // p 表示当前已经到达的位置，初始在入口 0

    for(int i = 1; i <= n + 1; i++){    // 遍历所有加油站，最后一个是终点
        ll dis = a[i].x - p;            // 从当前位置 p 到当前站点需要走的距离，也就是必须消耗的油量

        while(dis > 0){                 // 如果还需要消耗油
            if(pq_mi.empty()){          // 如果最便宜的候选油都没有了
                cout << -1 << '\n';     // 说明无法到达，输出 -1
                return 0;               // 直接结束程序
            }

            ll money = pq_mi.top();     // 取出当前最便宜的油价
            ll k = mp[money];           // 这个价格的油当前有多少单位
            ll need = min(k, dis);      // 本次最多消耗 need 单位这种油

            ans += need * money;        // 消耗 need 单位，累加花费
            dis -= need;                // 剩余需要消耗的油量减少
            t -= need;                  // 候选油总量减少
            mp[money] -= need;          // 该价格的油量减少

            if(mp[money] == 0){         // 如果这个价格的油已经用完
                pq_mi.pop();            // 从小根堆中弹出
            }
        }

        p = a[i].x;                     // 更新当前位置为当前站点位置

        if(i <= n){                     // 如果不是终点，说明可以在当前加油站加油
            ll money = a[i].y;          // 当前加油站的油价
            mp[money] += G;             // 先把“最多能加 G 单位这个价格的油”加入候选池
            t += G;                     // 候选油总量增加 G
            pq_mi.push(money);          // 把这个价格放入小根堆
            pq_mx.push(money);          // 把这个价格放入大根堆

            while(t > G){               // 如果候选油总量超过油箱容量 G
                ll d = pq_mx.top();     // 取出当前最贵的油价
                ll k = mp[d];           // 这个最贵价格的油有多少单位
                ll re = min(k, t - G);  // 需要丢掉 re 单位，最多丢掉这个价格的全部
                t -= re;                // 候选油总量减少
                mp[d] -= re;            // 该价格的油量减少

                if(mp[d] == 0){         // 如果这个最贵价格的油被丢完了
                    pq_mx.pop();        // 从大根堆中弹出
                }
            }
        }
    }

    cout << ans;                        // 输出最小花费
    return 0;                           // 程序结束
}