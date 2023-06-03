[P3371 【模板】单源最短路径（弱化版）](https://www.luogu.com.cn/problem/P3371)

> [Dijkstra](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%9C%80%E7%9F%AD%E8%B7%AF/Dijkstra.md)

注意最后输出的时候是INT_MAX 不是0x3f3f3f3f

```cpp
#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
const int N = 1e4 + 10, M = 5e5 + 10;
#else
const int N = 7, M = 20;
#endif
int n, m, s;
int dist[N];
bool vis[N];
struct edge {
  int v, w;
  explicit edge(int a, int b) : v(a), w(b) {}

  struct hash {
    size_t operator()(const edge &eg) const {
      return ((size_t) eg.v * INT_MAX + eg.w) % (9223372036854775807L * 2UL + 1UL);
    }
  };

  bool operator==(const edge &Rhs) const {
    return std::tie(v, w) == std::tie(Rhs.v, Rhs.w);
  }
  bool operator!=(const edge &Rhs) const {
    return !(Rhs == *this);
  }
};

struct node {
  int u, dis;

  bool operator>(const node &other) const {
    return dis > other.dis;
  }

};

unordered_set<edge, edge::hash> adjlst[N];

void dijkstra() {
  priority_queue<node, vector<node>, greater<>> q;
  memset(dist, 0x3f, sizeof dist);
  dist[s] = 0;
  q.push({s, 0});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    for (const auto &ed : adjlst[u]) {
      int v = ed.v;
      int w = ed.w;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        q.push({v, dist[v]});
      }
    }
  }
}

int main() {
  cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    adjlst[a].insert(edge(b, w));
  }

  dijkstra();

  for (int i = 1; i <= n; ++i)
    if (dist[i] < 0x3f3f3f3f )
      cout << dist[i] << " \n"[i == n];
    else
      cout << INT_MAX << " \n"[i == n];
  return 0;
}
```
