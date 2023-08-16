[P1775 石子合并（弱化版）](https://www.luogu.com.cn/problem/P1775)

> dp

```cpp
#include <bits/stdc++.h>

const int N = 300 + 10;
int a[N];
int f[N][N];

int get_sum(int l, int r) {
    return std::accumulate(a + l, a + r + 1, 0);
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        //    f[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            f[l][r] = INT_MAX;
            for (int k = l; k < r; ++k)
                f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r] + get_sum(l, r));
        }
    }
    std::cout << f[0][n-1] << "\n";
    return 0;
}

```


