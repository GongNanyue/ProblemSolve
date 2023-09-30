[P2015 二叉苹果树](https://www.luogu.com.cn/problem/P2015)

> 树形dp

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, q;
struct ade {
    int v, w;
};
vector<ade> adj[N];
int lc[N], rc[N], la[N], ra[N];
int f[N][N];

void dfs1(int u, int p) {
    for (auto [v, w]: adj[u])
        if (v != p) {
            dfs1(v, u);
            if (lc[u]) rc[u] = v, ra[u] = w;
            else lc[u] = v, la[u] = w;
            for (int j = 1; j <= q; ++j)
                for (int k = 0; k <= j; ++k) {
                    if (k == 0)
                        f[u][j] = max({f[u][j], f[rc[u]][j - 1] + ra[u]});
                    else if (k == j)
                        f[u][j] = max({f[u][j], f[lc[u]][k - 1] + la[u]});
                    else
                        f[u][j] = max({f[u][j], f[lc[u]][k - 1] + la[u] + f[rc[u]][j - k - 1] + ra[u]});
                }


        }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z}), adj[y].push_back({x, z});
    }
    dfs1(1, 1);
    cout << f[1][q] << "\n";

    return 0;
}
```
