[P3805 【模板】manacher 算法](https://www.luogu.com.cn/problem/P3805)

> Manacher

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1.1e7 + 10;
char a[N], s[3 * N];
int d[3 * N];

int main() {

    scanf("%s", a + 1);
    int n = strlen(a + 1);
    s[0] = '$';
    s[1] = '#';
    int k = 1;
    for (int i = 1; i <= n; ++i) {
        s[++k] = a[i];
        s[++k] = '#';
    }
    n = k;
    // 对字符串进行处理 s[0]加上开始符号$ 在每个字符的中间加上# 统一奇数和偶数长度的情况

    d[1] = 1;
    int l = 0, r = 1,mx = 0;
    for (int i = 2; i <= n; ++i) {
        if (i <= r) d[i] = min(d[l + r - i], r - i + 1);
        // 以i为中心的内回文串 与 边界的最小值
        while (s[i - d[i]] == s[i + d[i]]) d[i]++;
        // 内回文尝试增加
        if (i + d[i] - 1 > r) l = i - d[i] + 1, r = i + d[i] - 1;
        // 增加后超出边界 扩展边界

        mx = max(mx,d[i] - 1);
    }
    printf("%d", mx);

    return 0;
}
```
