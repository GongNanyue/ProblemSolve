


[P2910 [USACO08OPEN]Clear And Present Danger S](https://www.luogu.com.cn/problem/P2910)

> [Floyd](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%9C%80%E7%9F%AD%E8%B7%AF/Floyd.md)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#ifdef ONLINE_JUDGE
const int N = 110, M = 10010;
#else
const int N = 5, M = 5;
#endif
int n, m;
int path[M];

int dist[N][N];

void floyd() {
    for (int k = 1; k <= n; ++k)
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                dist[u][v] = min(dist[u][k] + dist[k][v], dist[u][v]);
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> path[i];
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> dist[i][j];

    floyd();

    ll res = 0;
    for (int i = 1; i < m; ++i) {
        res += dist[path[i - 1]][path[i]];
    }


    cout << res << "\n";
    return 0;
}

```
