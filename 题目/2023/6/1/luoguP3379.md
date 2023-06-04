[P3379 【模板】最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379)

> [树链剖分](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%A0%91%E4%B8%8A%E9%97%AE%E9%A2%98/%E6%A0%91%E9%93%BE%E5%89%96%E5%88%86.md)
> [最近公共祖先](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%A0%91%E4%B8%8A%E9%97%AE%E9%A2%98/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.md)


```cpp
#include <bits/stdc++.h>
using namespace std; //https://www.luogu.com.cn/problem/P3379
const int N = 5e5 + 10, M = 5e5 + 10;
int n, m, s;
vector<int> e[N];
int fa[N]/*father*/, depth[N], son[N], sz[N]/*size*/, top[N];

//  父节点(根节点s的父节点设为0)    重儿子  子树节点数量   重链顶点(指向轻儿子)
void dfs1(int u, int father) {//初始化fa, depth, sz, son
    fa[u] = father;
    depth[u] = depth[father] + 1;
    sz[u] = 1;
    for (auto v: e[u]) {
        if (v == father)continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]])
            son[u] = v;
    }
}

void dfs2(int u, int hd/*链头*/) {//初始化 top
    top[u] = hd;
    if (!son[u])return;//如果son[u] == 0 则说明没有子节点
    dfs2(son[u], hd);//重儿子连上重链
    for (auto v: e[u]) {//轻儿子开辟新的重链
        if (v == son[u] || v == fa[u])continue;
        dfs2(v, v);
    }
}


int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]])swap(u, v);
        u = fa[top[u]];
    }
    return depth[u] < depth[v] ? u : v;
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
            e[x].push_back(y);
            e[y].push_back(x);
        }
    }

    dfs1(s, 0);
    dfs2(s, s);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
    return 0;
}

```
