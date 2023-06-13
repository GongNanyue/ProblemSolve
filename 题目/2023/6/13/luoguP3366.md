[P3366 【模板】最小生成树](https://www.luogu.com.cn/problem/P3366)

> kruskal

```cpp

#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;

struct edge {
    int u, v, w;

    bool operator<(const edge &other) const {
        return w < other.w;
    }
};

vector<edge> es;
int n, m;

int leader[N];

int findleader(int u) {
    return leader[u] == u ? u : leader[u] = findleader(leader[u]);
}

void merge(int u, int v) {
    leader[findleader(u)] = findleader(v);
}

bool query(int u, int v) {
    return findleader(u) == findleader(v);
}

int kruskal() {
    int res = 0;
    vector<edge> l;
    for (const auto &ed: es) {
        int u = ed.u, v = ed.v, w = ed.w;
        if (!query(u, v)) {
            merge(u, v);
            l.push_back(ed);
            res += w;
        }
    }
    if (l.size() == n - 1)
        return res;
    else
        return -1;

}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        leader[i] = i;

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        es.push_back({a, b, w});
    }
    std::sort(es.begin(), es.end());

    auto res = kruskal();
    if(res == -1)
        cout << "orz\n";
    else
        cout << res << "\n";
    return 0;
}
```
