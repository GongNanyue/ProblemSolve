[P6175 无向图的最小环问题](https://www.luogu.com.cn/problem/P6175)

> [Floyd](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%9C%80%E7%9F%AD%E8%B7%AF/Floyd.md)
> [最小环](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%9C%80%E5%B0%8F%E7%8E%AF.md)

假设路径经过 u ---- v -----u 
而且要去和回的时候路径不同 不如设u ---- v 的时候是只经过 1 ~ k-1个点，v ---- u 的时候经过第k个点
u ---[1~k-1]--- v ---[k]--- u

然后再做floyd来把第k个点也包含在u---v的路径中

```cpp
#include <bits/stdc++.h>

const int N = 110, inf = 0x3f3f3f3f;
int n, m;
int Mtr[N][N];
int dist[N][N];


int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == j) dist[i][j] = Mtr[i][j] = 0;
            else dist[i][j] = Mtr[i][j] = inf;

    for (int i = 0; i < m; ++i) {
        int x, y, w;
        std::cin >> x >> y >> w;
        Mtr[x][y] = Mtr[y][x] = dist[x][y] = dist[y][x] = std::min(Mtr[x][y], w);
    }

    long long res = inf;
    for (int k = 1; k <= n; ++k) {
        for (int u = 1; u < k; ++u)
            for (int v = u + 1; v < k; ++v)
                res = std::min(res, (long long) dist[u][v] + Mtr[v][k] + Mtr[k][u]);
                //如果两个0x3f3f3f3f相加再加上一个常数就有可能溢出
                //或者inf 设为 0x2a2a2a2a

        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                dist[u][v] = dist[v][u] = std::min(dist[u][v], dist[u][k] + dist[k][v]);
    }

    if (res == inf)
        std::cout << "No solution.\n";
    else
        std::cout << res << "\n";
    return 0;
}

```
