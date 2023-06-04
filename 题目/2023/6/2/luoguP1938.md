[P1938 [USACO09NOV]Job Hunt S](https://www.luogu.com.cn/problem/P1938)

> [spfa](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%9C%80%E7%9F%AD%E8%B7%AF/spfa.md)



将获得的金钱设为负距离 
spfa求解最短路 距离为负数 取反+开始点获得的d即是答案
若spfa返回false 即是可以得到-Inf 就是可以获得无限的金钱
```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 250;
int d, p, c, f, s;
struct edge {
    int v, w;
};
vector<edge> adjlst[N];
int dist[N], cnt[N];
bool vis[N];
queue<int> q;

bool spfa() {
    memset(dist, 0x3f, sizeof N);
    dist[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (const auto &adj: adjlst[u]) {
            int v = adj.v, w = adj.w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= c)return false;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> d >> p >> c >> f >> s;
    for (int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        adjlst[a].push_back({b, -d});
    }
    for (int i = 0; i < f; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adjlst[a].push_back({b, -d + w});
    }
    bool res = spfa();
    if (!res)
        cout << -1 << "\n";
    else {
        int earn = 0x3f3f3f3f;
        for (int i = 1; i <= c; ++i)
            earn = min(earn, dist[i]);
        cout << -(earn) + d << "\n";

    }

    return 0;
}
```
