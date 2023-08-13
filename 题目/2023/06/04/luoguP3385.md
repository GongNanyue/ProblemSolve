[P3385 【模板】负环](https://www.luogu.com.cn/problem/P3385)

> [spfa](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%9C%80%E7%9F%AD%E8%B7%AF/spfa.md)

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+10;

int n, m;
struct edge {
    int v, w;
};

vector<edge> adjlst[N];
int dist[N], cnt[N];
bool vis[N];

bool spfa(int u) {
    memset(dist, 0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(vis, false, sizeof vis);
    queue<int> q;
    dist[u] = 0;
    vis[u] = true;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = false;

        for (const auto &ed: adjlst[u]) {
            int w = ed.w, v = ed.v;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)return false;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < N; ++i)
            adjlst[i].clear();

        for (int i = 0; i < m; ++i) {
            int x, y, w;
            cin >> x >> y >> w;
            if (w >= 0) {
                adjlst[x].push_back({y, w});
                adjlst[y].push_back({x, w});
            } else
                adjlst[x].push_back({y, w});
        }

        bool res = spfa(1);
        if (res)
            cout << "NO\n";
        else
            cout << "YES\n";
    }


    return 0;
}
```
