[P3387 【模板】缩点](https://www.luogu.com.cn/problem/P3387)

> 强连通分量 拓扑排序

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n, m, w[N];
vector<int> adj[N], G[N];
// adj 原来的图
// G[u] 缩点后的图 u是强连通分量所在的下标
int dfn[N], low[N], tc, st[N], tp, ins[N];
int scc[N], sz[N], sw[N], in[N], sc;
// sw 强连通分量中所有点权和
// in G图中的入度
int f[N];// 到达u点的路径最大权值和
void dfs(int u) {
    dfn[u] = low[u] = ++tc;
    st[++tp] = u, ins[u] = 1;
    for (auto v: adj[u])
        if (dfn[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v] == 1) {
            low[u] = min(low[u], dfn[v]);
        }
    if (dfn[u] == low[u]) {
        sc++;
        do {
            ins[st[tp]] = 0;
            scc[st[tp]] = sc;
            sz[sc]++;
            sw[sc] += w[st[tp]];
        } while (st[tp--] != u);
    }
}

void tarjan() {
    for (int i = 1; i <= n; ++i)
        if (dfn[i] == 0)
            dfs(i);
}

void topo() {

}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    tarjan();
    // 重新建图G
    for (int i = 1; i <= n; ++i)
        for (auto j: adj[i])
            if (scc[i] != scc[j]) {
                G[scc[i]].push_back(scc[j]);
                in[scc[j]]++;
            }
    
    // 拓扑排序
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        f[u] += sw[u];
        for (auto v: G[u]) {
            in[v]--;
            f[v] = max(f[v], f[u]);
            if (in[v] == 0) q.push(v);
        }
    }

    int ans = 0;
    for(int i = 1;i <= n;++i) ans = max(ans,f[i]);
    cout << ans << "\n";
    return 0;
}
```
