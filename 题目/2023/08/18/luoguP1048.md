[P1048 [NOIP2005 普及组] 采药](https://www.luogu.com.cn/problem/P1048)

> 背包dp

01背包


```cpp
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
template<typename T>
using Vec = std::vector<T>;


int main() {
    int T, M;
    std::cin >> T >> M;
    Vec<int> v(M + 1), w(M + 1);
    for (int i = 1; i <= M; ++i)
        std::cin >> v[i] >> w[i];
    Vec<Vec<int>> f(M + 1, Vec<int>(T + 1));

    for (int i = 1; i <= M; ++i)
        for (int j = 0; j <= T; ++j) {
            if (j - v[i] >= 0)
                f[i][j] = std::max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            else
                f[i][j] = f[i - 1][j];
        }
    std::cout << f[M][T] << "\n";

    return 0;
}
```
