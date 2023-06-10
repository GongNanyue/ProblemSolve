[E - Art Gallery on Graph](https://atcoder.jp/contests/abc305/tasks/abc305_e)
>[Dijkstra](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%9C%80%E7%9F%AD%E8%B7%AF/Dijkstra.md)


博客题解
https://www.cnblogs.com/Lanly/p/17472104.html


我们可以也增加一个起点st，该起点与 k个关键点都连边。至于边权，因为每个关键点的监视距离不一样，因此为了统一最后的判断（距离起点 st的距离），我们设关键点中最大的监视距离为 maxx，则 st→ki的边权为 maxx−hi，这样最后从起点跑一遍最短路后，与起点距离不超过 maxx的点都被监视了。

注意这个起点st是我们额外加的，实际不存在，要防止关键点通过起点监视了其他点，因此要设 ki→st的距离为无穷大。

因为增加了额外点和额外边，边权不再是1了。因此不能跑 BFS，可以跑 Dijkstra。


```cpp
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
int n, m, k;

struct edge {
    int v, w;

    edge(int v, int w) : v(v), w(w) {}
};

struct node {
    int u, dis;

    node(int u, int dis) : u(u), dis(dis) {}

    bool operator>(const node &other) const {
        return dis > other.dis;
    }
};

vector<edge> adjlst[N];
pair<int, int> gs[N];
int dist[N];

void dijkstra(int u) {
    priority_queue<node, vector<node>, greater<>> q;
    bool vis[N];

    memset(dist, 0x3f, sizeof dist);
    dist[u] = 0;
    memset(vis, false, sizeof vis);
    q.push(node(u, 0));

    while (!q.empty()) {
        u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (const edge &ed: adjlst[u]) {
            int v = ed.v, w = ed.w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({v, dist[v]});
            }
        }
    }
}


int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adjlst[a].push_back({b, 1});
        adjlst[b].push_back({a, 1});
    }
    int maxGp = 0, maxGh = 0;

    for (int i = 0; i < k; ++i) {
        int p, h;
        cin >> p >> h;
        gs[i] = {p, h};
        if (h > maxGh) {
            maxGh = h;
            maxGp = p;
        }
    }

    for (const auto &g: gs) {
        int p = g.first, h = g.second;
        adjlst[0].push_back({p, maxGh - h});
        adjlst[p].push_back({0, inf});
    }

    dijkstra(0);
    vector<int> res;
    for (int i = 1; i <= n; ++i)
        if (dist[i] <= maxGh)
            res.push_back(i);
    cout << res.size() << "\n";
    for(auto idx : res )
        cout << idx << " ";

    return 0;
}
```
