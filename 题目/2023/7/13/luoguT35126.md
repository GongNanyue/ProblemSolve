[T351264 醋溜便当](https://www.luogu.com.cn/problem/T351264)


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
