[T351264 醋溜便当](https://www.luogu.com.cn/problem/T351264)

容易发现，如果从 𝑥 出发有一条长度为 𝑎 的回路，那么可以不断
绕回路走，走出长度为 2𝑎, 3𝑎, ⋯ 的回路。
题设范围是 [𝑥, 𝑘𝑥]。如果从 𝑥 出发有一条长度不超过 𝑥 且大于 0
的的回路，那么总可以不断重复，直到回路长度在 𝑥, 𝑘𝑥 内。
于是问题转化为了， 对每个点找一条最短的回路。
• 由于原图是无向图，因此总可以走到第一个正权边后，原路返
回。于是若回路上有两种不同的正权，一定不优。
• 由于原图有零权边，因此有可能整个过程就经过一次正权边。
可以用并查集维护  


```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, x, k;

struct edge {
    int u, v, w;

    edge(int a = 0, int b = 0, int c = 0) : u(a), v(b), w(c) {}
};

vector<edge> es;
vector<int> p;
vector<int> ans;

int findp(int u) {
    return p[u] == u ? u : p[u] = findp(p[u]);
}

void merge(int u, int v) {
    p[findp(u)] = findp(v);
}

bool query(int u, int v) {
    return findp(u) == findp(v);
}

int main() {
    cin >> n >> m >> x >> k;
    es.assign(m, edge());
    ans.assign(n + 1, INT_MAX);
    for (int i = 0; i <= n; ++i)p.push_back(i);
    for (int i = 0; i < m; ++i) {
        cin >> es[i].u >> es[i].v >> es[i].w;
        if (es[i].w == 0) {
            merge(es[i].u, es[i].v);
        }
    }

    for (auto [u, v, w]: es) {
        int pu = findp(u), pv = findp(v);
        if (w != 0) {
            if (pu == pv) {
                ans[pu] = min(ans[pu], w);
            } else {
                ans[pu] = min(ans[pu], 2 * w);
                ans[pv] = min(ans[pv], 2 * w);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << (ans[findp(i)] <= x * k) << " ";
    }

    return 0;
}
```
