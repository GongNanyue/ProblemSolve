[P1435 [IOI2000] 回文字串](https://www.luogu.com.cn/problem/P1435)

> 区间dp

对于程度为1显然是回文串，长度为2只有两个字符相等才是回文串

对于长度在3以上的如果首字符和尾字符相等，则可以转移到dp[i+1][j-1]
如果不相等 可以在字符串前面加上一个与尾字符相同的字符dp[i][j-1] + 1，也可以在最后加上与首字符相等的字符dp[i+1][j] + 1

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
char s[N];
int n;
int dp[N][N];

int main() {
    cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
//        dp[i][i] = 0;
        if (i != n && s[i] != s[i + 1])
            dp[i][i + 1] = 1;
    }

    for (int l = 3; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else {
                dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}
```
