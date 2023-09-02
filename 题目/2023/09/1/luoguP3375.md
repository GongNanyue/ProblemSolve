[P3375 【模板】KMP 字符串匹配](https://www.luogu.com.cn/problem/P3375)https://www.luogu.com.cn/problem/P3375

> kmp

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
char s[N], t[N];
int sn, tn;
int p[N];//π数组 t[1..i]中真前缀真后缀相同最长长度

void calPi() {
//    p[0] = p[1] = 0;
    for (int i = 2, j = 0; i <= tn; ++i) {
        // j 表示相同真前后缀长度 0表示没有
        while (j != 0 && t[j + 1] != t[i]) j = p[j];
        if (t[j + 1] == t[i]) p[i] = ++j;
//        else p[i] = 0;
    }
}

void kmp() {
    for (int i = 1, j = 0; i <= sn; ++i) {
        while (j != 0 && t[j + 1] != s[i]) j = p[j];
        if (t[j + 1] == s[i]) ++j;
        if (j == tn) {
            printf("%d\n", i - tn + 1);
            j = p[j];
        }
    }
}

int main() {
    // 字符串下标从1开始
    scanf("%s", s + 1);// s[1:sn] 文本串
    scanf("%s", t + 1);// t[1:tn]  模式串
    sn = strlen(s + 1);
    tn = strlen(t + 1);
    calPi();
    kmp();
    for (int i = 1; i <= tn; ++i)
        printf("%d ", p[i]);

    return 0;
}
```
