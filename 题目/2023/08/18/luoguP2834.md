[P2834 纸币问题 3](https://www.luogu.com.cn/problem/P2834)

> 背包dp

完全背包的变式

把纸币的价格看做物品体积，把凑成的钱看成背包的体积，所求的是方案数



设$f[i,j]$是选前i的物品，恰好装满j的体积


$$
f[i,j] \newline
= sum(f[i-1][j],f[i-1][j-a[i]],f[i-1][j-2*a[i]].....) \newline
= sum(f[i-1][j],f[i][j-a[i]])
$$




```cpp
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
template<typename T>
using Vec = std::vector<T>;


int main() {
    ll n, w, mod = 1e9 + 7;
    std::cin >> n >> w;
    Vec<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) std::cin >> a[i];
    Vec<Vec<ll>> f(n + 1, Vec<ll>(w + 1));

    f[0][0] = 1;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 0; j <= w; ++j) {
            for (ll k = 0; k * a[i] <= j; ++k)
                f[i][j] += f[i - 1][j - k * a[i]];
            f[i][j] %= mod;
        }

    std::cout << f[n][w] << "\n";
    return 0;
}
```

```cpp
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
template<typename T>
using Vec = std::vector<T>;


int main() {
    ll n, w, mod = 1e9 + 7;
    std::cin >> n >> w;
    Vec<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) std::cin >> a[i];
    Vec<Vec<ll>> f(n + 1, Vec<ll>(w + 1));

    f[0][0] = 1;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 0; j <= w; ++j) {
            f[i][j] = f[i - 1][j];
            if (j - a[i] >= 0)f[i][j] += f[i][j - a[i]];


            f[i][j] %= mod;
        }

    std::cout << f[n][w] << "\n";
    return 0;
}
```
