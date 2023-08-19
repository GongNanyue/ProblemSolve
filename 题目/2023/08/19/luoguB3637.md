
[B3637 最长上升子序列](https://www.luogu.com.cn/problem/B3637)

> 线性dp

```cpp
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;

const int N = 5e3 + 10;
int a[N];
int f[N];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        f[i] = 1;
    }
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if (a[i] > a[j])
                f[i] = std::max(f[i], f[j] + 1);

    int mx = 0;
    for(int i = 1;i <= n;++i)
        mx = std::max(mx,f[i]);
    std::cout << mx << "\n";

    return 0;
}
```
