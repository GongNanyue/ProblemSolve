[P3379 【模板】最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379)


> [最近公共祖先](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%A0%91%E4%B8%8A%E9%97%AE%E9%A2%98/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.md)

倍增算法实现

注意开O2优化 和 关闭同步


```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, s;
vector<int> adjlst[N];
int depth[N], ancestor[N][20];//2 ^ 20 ~= 1e6

void dfs(int u, int father) {
    depth[u] = depth[father] + 1;
    ancestor[u][0] = father;

    for (int i = 1; i <= 19; ++i)
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];

    for (int v: adjlst[u])
        if (v != father)
            dfs(v, u);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v); // 确保u的深度更深

    //先将u v跳到同一层
    for (int i = 19; i >= 0; --i)
        if (depth[ancestor[u][i]] >= depth[v])
            u = ancestor[u][i];

    if (u == v)return u;//特判就已经到了最近公共祖先

    //一起向上跳到最近公共祖先的下一层的位置
    for (int i = 19; i >= 0; --i)
        if (ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    return ancestor[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        if (x != y) {
            adjlst[x].emplace_back(y);
            adjlst[y].emplace_back(x);
        }
    }

    dfs(s, 0);//0 作为哨兵节点 是根节点的祖宗节点

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
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
