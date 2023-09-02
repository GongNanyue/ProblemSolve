[P3435 [POI2006] OKR-Periods of Words](https://www.luogu.com.cn/problem/P3435)

> kmp

```cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
char s[N];
int n, p[N];
int f[N]; 
// 在失配树到根节点的链最靠近根节点的子节点的长度
// 由于题目求的是最长的周期 周期 = i - p[i] 那么就要标记当前位置最短的border
void getPi() {
    for (int i = 2, j = 0;i  <= n; ++i) {
        while (j != 0 && s[j + 1] != s[i]) j = p[j];
        if (s[j + 1] == s[i]) p[i] = ++j;
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);

    getPi();

    ll ans = 0;// long long
    for (int i = 1; i <= n; ++i) {
        if (p[i] == 0) f[i] = i;
        else f[i] = f[p[i]];

        if (p[i] != 0) 
            ans += i - f[i];
        // 如果p[i]是0 表明没有border 那么没有周期
    }
    printf("%lld\n", ans);
    return 0;
}
```
