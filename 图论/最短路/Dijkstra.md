模板[P4779 【模板】单源最短路径（标准版）](https://www.luogu.com.cn/problem/P4779)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int n, m, s;

struct edge {
    int u, w;
};

struct node {
    int u, dis;

    bool operator>(const node &rhs) const {
        return dis > rhs.dis;
    }
};

vector<vector<edge>> adj;
vector<int> dis;

void dijkstra() {
    dis.assign(n + 1, inf);
    priority_queue<node, vector<node>, greater<>> q;
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty()) {
        auto [u, du] = q.top();
        q.pop();
        if (du > dis[u]) continue;
        for (auto [v, w]: adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkstra();
    for (int i = 1; i <= n; ++i)
        cout << dis[i] << " \n"[i == n];
    return 0;
}
```

```cpp
struct edge {
  int v, w;
};

struct node {
  int dis, u;

  bool operator>(const node& a) const { return dis > a.dis; }
};

vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node> > q;

void dijkstra(int n, int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

```

