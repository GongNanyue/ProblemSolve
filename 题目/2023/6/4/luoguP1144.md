[P1144 最短路计数](https://www.luogu.com.cn/problem/P1144)

> [广度优先搜索](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%90%9C%E7%B4%A2/%E5%B9%BF%E5%BA%A6%E4%BC%98%E5%85%88%E6%90%9C%E7%B4%A2.md)

在所有访问到的边中 如果是和u相隔1 则说明是直接访问的 那么v的路径个数就是再加上u的路径个数

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 100003;
int n, m;
vector<int> adjlst[N];
int cnt[N], dist[N];
bool vis[N];

void bfs(int u) {
    memset(cnt, 0, sizeof cnt);
    memset(vis, false, sizeof vis);
    memset(dist, 0x3f, sizeof dist);
    vis[u] = true;
    cnt[u] = 1;
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v: adjlst[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
            if(dist[v] ==  dist[u] + 1)
                cnt[v] = (cnt[v] + cnt[u]) % mod;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adjlst[x].push_back(y);
        adjlst[y].push_back(x);
    }
    bfs(1);
    for (int i = 1; i <=n; ++i)
        cout << cnt[i] << "\n";
    return 0;
}
```

