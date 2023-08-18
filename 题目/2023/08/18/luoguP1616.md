[P1616 疯狂的采药](https://www.luogu.com.cn/problem/P1616)
> 背包dp

多重背包朴素版本(80pts)TLE20pts
```cpp
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
template<typename T>
using Vec = std::vector<T>;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {
    int t, m;
    std::cin >> t >> m;
    Vec<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; ++i)
        std::cin >> a[i] >> b[i];
    Vec<Vec<int>> f(m + 1, Vec<int>(t + 1));
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j <= t; ++j) {
            for (int k = 0; j - k * a[i] >= 0; ++k)
                f[i][j] = std::max(f[i][j], f[i - 1][j - k * a[i]] + k * b[i]);
        }

    std::cout << f[m][t] << "\n";
}
```

时间优化(90pts) int溢出

```cpp
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
template<typename T>
using Vec = std::vector<T>;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {
    int t, m;
    std::cin >> t >> m;
    Vec<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; ++i)
        std::cin >> a[i] >> b[i];
    Vec<Vec<int>> f(m + 1, Vec<int>(t + 1));

    for (int i = 1; i <= m; ++i)
        for (int j = 0; j <= t; ++j) {
            if (j - a[i] >= 0)
                f[i][j] = std::max(f[i - 1][j], f[i][j - a[i]] + b[i]);
            else
                f[i][j] = f[i-1][j];

        }

    std::cout << f[m][t] << "\n";
}
```

空间优化 longlong
```cpp
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
template<typename T>
using Vec = std::vector<T>;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {
    int t, m;
    std::cin >> t >> m;
    Vec<ll> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; ++i)
        std::cin >> a[i] >> b[i];
    Vec<ll> f(t + 1);

    for (int i = 1; i <= m; ++i)
        for (int j = 0; j <= t; ++j) {
            if (j - a[i] >= 0)
                f[j] = std::max(f[j], f[j - a[i]] + b[i]);
            else
                f[j] = f[j];
        }
    std::cout << f[t] << "\n";
}
```
