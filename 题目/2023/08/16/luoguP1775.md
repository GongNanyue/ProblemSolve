[P1775 石子合并（弱化版）](https://www.luogu.com.cn/problem/P1775)

> 区间dp

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


使用前缀和优化求和

```cpp
#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 310l;
int a[N], sm[N], n, dp[N][N];


int main() {
    cin >> n;
    memset(dp,0x3f,sizeof dp);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sm[i] = sm[i - 1] + a[i];
        dp[i][i] = 0;
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i + l - 1 <= n; ++i) {
            int j = i + l - 1;
            for (int k = i; k <= j - 1; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sm[j] - sm[i - 1]);


        }
    }

    cout << dp[1][n] << "\n";
    return 0;
}
```
