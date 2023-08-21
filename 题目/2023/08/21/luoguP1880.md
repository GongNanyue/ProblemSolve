[P1880 [NOI1995] 石子合并](https://www.luogu.com.cn/problem/P1880)

> 区间dp

倍长断环成链 可以把环复制一份 然后在区间长度为n上找

```cpp
#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 110;
int a[2 * N], mn[2 * N][2 * N], mx[2 * N][2 * N], sm[2 * N];
int n;

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
        mn[i][i] = mn[n + i][n + 1] =
        mx[i][i] = mx[n + i][n + i] = 0;
    }
    for (int i = 1; i <= 2 * n; ++i)
        sm[i] = sm[i - 1] + a[i];

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= 2 * n; ++i) {
            int j = i + len - 1;
            mn[i][j] = inf;
            mx[i][j] = -inf;

            for (int k = i; k < j; ++k) {
                mn[i][j] = min(mn[i][j], mn[i][k] + mn[k + 1][j] + sm[j] - sm[i - 1]);
                mx[i][j] = max(mx[i][j], mx[i][k] + mx[k + 1][j] + sm[j] - sm[i - 1]);
            }
        }
    }

    int ans0 = inf, ans1 = -inf;
    for (int i = 1; i + n - 1 <= 2 * n; ++i) {
        int j = i + n - 1;
        ans0 = min(ans0, mn[i][j]);
        ans1 = max(ans1, mx[i][j]);
    }
    cout << ans0 << "\n" << ans1 << "\n";
    return 0;
}
```
