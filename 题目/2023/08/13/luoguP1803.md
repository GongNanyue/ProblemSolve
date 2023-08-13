[P1803 凌乱的yyy / 线段覆盖](https://www.luogu.com.cn/problem/P1803)


> 贪心

优化的贪心要留后路

```cpp
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;


struct seg {
    int l, r;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<seg> ss(n);
    for (int i = 0; i < n; ++i)
        std::cin >> ss[i].l >> ss[i].r;

    std::sort(ss.begin(), ss.end(),
              [](auto a, auto b) {
                  if (a.r != b.r) return a.r < b.r;
                  else return a.l > b.l;
              });

    int cnt = 1;
    int l = ss[0].l, r = ss[0].r;
    for (int i = 1; i < n; ++i) {
        if (ss[i].r == r) continue;
        if (ss[i].l < r) continue;
        ++cnt;
        l = ss[i].l, r = ss[i].r;
    }
    std::cout << cnt << "\n";

    return 0;
}
```
