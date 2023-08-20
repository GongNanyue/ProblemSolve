[P1544 三倍经验](https://www.luogu.com.cn/problem/P1544)


> dp

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// -inf 是-3e9 超过int
const int N = 110;
ll a[N][N], dp[N][N][N * (N + 1) / 2];
ll n, p;

int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
        //i = 1开始赋值成-inf,i = 0留为0 方便i = 1时候的dp
        for (int j = 0; j <= i + 1; ++j)//下一行的最后一个会用到j = n + 1 这个值
            for (int k = 0; k <= p; ++k)
                dp[i][j][k] = -4e10;



    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            for (int k = 0; k <= i && k <= p; ++k) {
                if (k >= 1)
                    dp[i][j][k] = max({
                                              dp[i - 1][j][k] + a[i][j],
                                              dp[i - 1][j][k - 1] + 3 * a[i][j],
                                              dp[i - 1][j - 1][k] + a[i][j],
                                              dp[i - 1][j - 1][k - 1] + 3 * a[i][j]
                                      });
                else
                    dp[i][j][k] = max({
                                              dp[i - 1][j][k] + a[i][j],
                                              dp[i - 1][j - 1][k] + a[i][j],
                                      });

            }


    ll ans = -4e10;
    for (int j = 1; j <= n; ++j)
        for (int k = 0; k <= min(p,n); ++k)
            // 由于a的值可能为负数 所以乘3可能使得答案变小 所以要遍历所有k
            ans = max(ans, dp[n][j][k]);
    cout << ans << "\n";
    return 0;
}
```
