[P1725 琪露诺](https://www.luogu.com.cn/problem/P1725)


> 线性dp

```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
//不能使用INT_MAX 不然会溢出int
const int N = 2e5 + 10;

//const int N = 7;
int a[N], dp[N];
int l, r, n;

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        dp[i] = -INF;
        for (int j = l; j <= r && i - j >= 0; ++j) {
            dp[i] = max(dp[i], dp[i - j] + a[i]);
            //不能使用INT_MAX 不然会溢出int
            // a[i] 有可能是负数
        }
    }
    int ans = -INF;// ans 有可能是负数
    for (int i = n - r + 1; i <= n; ++i)
        ans = max(ans, dp[i]);
    cout << ans << "\n";

    return 0;
}
```
