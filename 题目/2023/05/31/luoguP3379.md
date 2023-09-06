[P3379 【模板】最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379)


> [最近公共祖先](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%A0%91%E4%B8%8A%E9%97%AE%E9%A2%98/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.md)

倍增算法实现

注意开O2优化 和 关闭同步


```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 10;
int n, m, s;
vector<int> adj[N];
int dpt[N];// depth
int fa[N][20]; // log2(N) = 18.93

void dfs(int u, int p) {
    // 预处理O(n log n)
    dpt[u] = dpt[p] + 1;
    fa[u][0] = p;

    for (int i = 1; i < 20; ++i)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    // 上跳2^k次等于先上跳到2^(k-1)的节点再上跳到2^(k-1)次

    for (auto v: adj[u])
        if (v != p)
            dfs(v, u);
}

int lca(int a, int b) {
    // 查询O(log n)
    if (dpt[a] < dpt[b]) swap(a, b);
    // 假定a的深度更深
    for (int i = 19; i >= 0; --i)
        if (dpt[fa[a][i]] >= dpt[b])
            a = fa[a][i];
    // 如果上跳的祖先还是比b要深 那么上跳
    if (a == b) return a;// 如果是同一个节点 那么特判返回

    for (int i = 19; i >= 0; --i)
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }
    // 如果上跳2^i次后的祖先相等 说明祖先在lca到根节点的路径上 那么跳多了
    // 如果不相等 说明祖先不在路径上 可以上跳
    // 时刻保障上跳到lca的下面
    // 经过二进制拆分 那么最后两个节点恰好就是lca的儿子
    return fa[a][0];
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    dfs(s, 0);
    // 0 是哨兵节点 深度是0
    // 可以让fa上跳过多fa[u][inf] = 0为哨兵节点
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
    return 0;
}
```



tarjan算法

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 5e5 + 10;
int n, m, s;
vector<int> e[N];  //edge[本节点] ={对节点...} 
vector<pair<int, int>> query[N];
// 查询对面的节点  查询编号   query[查询本节点]
int leader[N], vis[N], ans[M];

int find(int x) {
    return leader[x] == x ? x : (leader[x] = find(leader[x]));
} // 并查集查找leader

void tarjan(int u) {
    vis[u] = 1;
    for (auto v: e[u]) {
        if (!vis[v]) {
            tarjan(v);
            leader[v] = u;
            //连上并查集
        }
    }
    for (auto q: query[u]) {
        int v = q.first, i = q.second;
        if (vis[v]) ans[i] = find(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
        leader[i] = i;

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        if (x != y) {
            e[x].emplace_back(y);
            e[y].emplace_back(x);
        }
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        query[a].emplace_back(b, i);
        query[b].emplace_back(a, i);
    }
    tarjan(s);
    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";


    return 0;
}
```
