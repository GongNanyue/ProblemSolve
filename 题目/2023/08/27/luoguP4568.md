[P4568 [JLOI2011] 飞行路线](https://www.luogu.com.cn/problem/P4568)

> dijkstra 分层图

```cpp
#include <bits/stdc++.h>
using namespace std;


const int inf = 0x3f3f3f3f;
int n, m, k, s, t;

struct point {
    int layer, u;


    point(int layer, int u) : layer(layer), u(u) {}

    struct hash {
        size_t operator()(const point &p) const {
            return 1ull * p.layer * INT_MAX + p.u;
        }
    };

    bool operator==(const point &rhs) const {
        return layer == rhs.layer &&
               u == rhs.u;
    }

};

struct edge {
    point v;
    int w;
};

struct node {
    point u;
    int dis;

    bool operator>(const node &rhs) const {
        return dis > rhs.dis;
    }
};

unordered_map<point, vector<edge>, point::hash> adj;
unordered_map<point, int, point::hash> dist;


void dijkstra() {
    priority_queue<node, vector<node>, greater<>> q;
    q.push({{0, s}, 0});
    for (int i = 0; i <= k; ++i)
        for (int j = 0; j < n; ++j)
            dist[{i, j}] = inf;
    dist[{0, s}] = 0;

    while (!q.empty()) {
        auto [u, du] = q.top();
        q.pop();
        if (du > dist[u]) continue;
        for (auto [v, w]: adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({v, dist[v]});
            }
        }
    }

}


int main() {

    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 0; j <= k; ++j) {
            adj[{j, a}].push_back({{j, b}, c});
            adj[{j, b}].push_back({{j, a}, c});
        }
        for (int j = 0; j < k; ++j) {
            adj[{j, a}].push_back({{j + 1, b}, 0});
            adj[{j, b}].push_back({{j + 1, a}, 0});
        }
    }

    dijkstra();
    int ans = inf;
    for(int i = 0;i <= k;++i)
        ans = min(ans,dist[{i,t}]);
    cout << ans << "\n";


    return 0;
}


```
