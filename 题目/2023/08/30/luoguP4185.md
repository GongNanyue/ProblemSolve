[P4185 [USACO18JAN] MooTube G](https://www.luogu.com.cn/problem/P4185)

> 并查集 离线

询问的k从大到小排列 然后边的r也从大到小加入合并


```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, qn;
int fa[N], sz[N];

int find(int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
}


bool same(int u, int v) {
    return find(u) == find(v);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
//    fa[find(u)] = find(v);
//    sz[find(v)] += sz[find(u)];
//    这样写是不对的 因为经过上面一句之后 v的祖宗节点发生了变化
    fa[u] = v;
    sz[v] += sz[u];
}

struct edge {
    int p, q, r;

    edge() = default;
};

struct query {
    int k, v;
    int idx;

    query() = default;
};

int main() {
    cin >> n >> qn;

    iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= n; ++i) sz[i] = 1;

    vector<edge> e(n - 1);
    for (int i = 0; i < n - 1; ++i) cin >> e[i].p >> e[i].q >> e[i].r;

    vector<query> q(qn);
    for (int i = 0; i < qn; ++i) {
        q[i].idx = i;
        cin >> q[i].k >> q[i].v;
    }

    sort(e.begin(), e.end(), [](auto a, auto b) { return a.r > b.r; });
    sort(q.begin(), q.end(), [](auto a, auto b) { return a.k > b.k; });

    int i = 0;
    vector<int> ans(qn);
    for (auto [k, v, idx]: q) {
        while (i < e.size() && e[i].r >= k) {
            merge(e[i].p, e[i].q);
            ++i;
        }
        ans[idx] = sz[find(v)] - 1;
    }

    for (int k = 0; k < qn; ++k)
        cout << ans[k] << "\n";
    return 0;
}
```
