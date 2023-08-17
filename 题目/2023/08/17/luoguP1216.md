[P1216 [USACO1.5] [IOI1994]数字三角形 Number Triangles](https://www.luogu.com.cn/problem/P1216)


> dp

```cpp
#include <bits/stdc++.h>

const int N = 1010;
int a[N][N];
int f[N][N];


int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            std::cin >> a[i][j];
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            f[i][j] = std::max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
    int ans = 0;
    for(int i = 1;i <= n;++i) ans = std::max(ans,f[n][i]);
    std::cout << ans << "\n";
    return 0;
}
```
