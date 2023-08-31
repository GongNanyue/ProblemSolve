[P3375 【模板】KMP 字符串匹配](https://www.luogu.com.cn/problem/P3375)https://www.luogu.com.cn/problem/P3375

> kmp

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

char txt[N], pat[N];
int tn, pn;
int pit[N], pip[N];

int main() {
    scanf("%s", txt + 1);
    scanf("%s", pat + 1);
    tn = strlen(txt + 1);
    pn = strlen(pat + 1);

    pip[0] = pip[1] = 0;
    for (int i = 2; i <= pn; ++i) {
        int p = pip[i - 1];
        while (p != 0) {
            if (pat[p + 1] == pat[i]) break;
            else p = pip[p];
        }
        if (pat[p + 1] == pat[i]) pip[i] = p + 1;
        else pip[i] = 0;
    }

    for (int i = 1; i <= tn; ++i) {
        int p = pit[i - 1];
        while (p != 0) {
            if (pat[p + 1] == txt[i]) break;
            else p = pip[p];
        }
        if (pat[p + 1] == txt[i]) pit[i] = p + 1;
        else pit[i] = 0;

        if (pit[i] == pn) printf("%d\n", i - pn + 1);
    }

    for (int i = 1; i <= pn; ++i)
        printf("%d ", pip[i]);

    return 0;
}
```
