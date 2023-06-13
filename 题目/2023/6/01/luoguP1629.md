[P1629 邮递员送信](https://www.luogu.com.cn/problem/P1629)

> [Floyed](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%9C%80%E7%9F%AD%E8%B7%AF/Floyed.md)

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
using ll = long long;
ll dist[N][N];
int n, m;

void floyd() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        if (u != v)
            dist[u][v] = min(dist[u][v], w);
    }
    floyd();
    ll sum = 0;
    for (int i = 2; i <= n; ++i)
        sum += (dist[1][i] + dist[i][1]);
    cout << sum << "\n";
    return 0;
}
```
