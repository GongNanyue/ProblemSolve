[P1197 [JSOI2008] 星球大战](https://www.luogu.com.cn/problem/P1197)

> 并查集 离线

并查集只能连接连通块，那么删除点就相当于倒着连接点

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;
int n, m, k, f[N];

int find(int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
}

void merge(int u, int v) {
    f[find(u)] = find(v);
}

bool same(int u, int v) {
    return find(u) == find(v);
}


int main() {
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) f[i] = i;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    cin >> k;
    vector<int> cut(k);
    unordered_set<int> v;

    for (int i = 0; i < k; ++i) {
        cin >> cut[i];
        v.insert(cut[i]);
    }
    int now = n - k;// 假设每一个点都是孤立的
    for (int i = 0; i < n; ++i)
        if (v.count(i) == 0)
            for (auto j: adj[i])
                if (v.count(j) == 0 && !same(i, j)) {
                    merge(i, j);
                    now--;
                    //不在同一个连通块中相连接 连通分量减少
                }
    vector<int> ans{now};
    for (int i = k - 1; i >= 0; --i) {
        v.erase(cut[i]);
        ++now;// 增加一个新的孤立的点 连通块增加
        for (auto j: adj[cut[i]])
            if (v.count(j) == 0 && !same(cut[i], j)) {
                merge(cut[i], j);
                --now;
            }
        ans.push_back(now);
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << "\n";
    return 0;
}
```
