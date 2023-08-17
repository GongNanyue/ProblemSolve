[P2842 纸币问题 1](https://www.luogu.com.cn/problem/P2842)


> dp

```cpp
#include <bits/stdc++.h>
int main() {
    int n, w;
    std::cin >> n >> w;
    std::vector<int> a(n), f(w + 1, INT_MAX / 2);
    f[0] = 0;
    for (int i = 0; i < n; ++i)std::cin >> a[i];
    for (int i = 1; i <= w; ++i) {
        for (auto v: a) {
            if (i - v >= 0) {
                f[i] = std::min(f[i], f[i - v] + 1);
            }
        }
    }
    std::cout << f[w] << "\n";
    return 0;
}
```
