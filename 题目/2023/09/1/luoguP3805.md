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
    s[0] = '$';// 开始字符串
    s[1] = '#';
    int k = 1;
    for (int i = 1; i <= n; ++i) {
        s[++k] = a[i];
        s[++k] = '#';
    }
    n = k;

    d[1] = 1;
    int l = 0, r = 1,mx = 0;
    for (int i = 2; i <= n; ++i) {
        if (i <= r) d[i] = min(d[l + r - i], r - i + 1);
        while (s[i - d[i]] == s[i + d[i]]) d[i]++;
        if (i + d[i] - 1 > r) l = i - d[i] + 1, r = i + d[i] - 1;

        mx = max(mx,d[i] - 1);
    }
    printf("%d", mx);

    return 0;
}
```
