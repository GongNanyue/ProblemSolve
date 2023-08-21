[P3205 [HNOI2010] 合唱队](https://www.luogu.com.cn/problem/P3205)

> 区间dp

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 19650827;
const int N = 1010;
ll a[N], dp[N][N][2];
// dp最后一位表示最后一个进来的人是放在左边0还是放在右边1
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i][i][0]= 1;
        //不能0/1同时为1
        //不然的话 只有一个人的时候就会有两种方案 显然是错误的
        // 不妨假设一个人的时候都是从左边进来的
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;

            if (a[i] < a[i + 1])
                dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][0]) % mod;
            if (a[i] < a[j])
                dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][1]) % mod;


            if (a[j] > a[i])
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][0]) % mod;
            if (a[j] > a[j - 1])
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1]) % mod;
        }
    }

    cout << (dp[1][n][0] + dp[1][n][1]) % mod << "\n";
    return 0;
}
```
