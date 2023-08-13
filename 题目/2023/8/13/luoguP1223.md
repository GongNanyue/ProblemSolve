[P1223 排队接水](https://www.luogu.com.cn/problem/P1223)


> 贪心

每个人对于等待总时间的贡献是(n-i) * time(i)

```cpp
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;


struct P {
    int idx;
    int tm;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<P> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].tm;
        a[i].idx = i + 1;
    }
    std::sort(a.begin(), a.end(),
              [](auto p, auto q) {
                  return p.tm < q.tm;
              });
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << a[i].idx << " \n"[i == n - 1];
        sum += (n - i - 1) * a[i].tm;
    }
    std::cout << std::fixed << std::setprecision(2)
              << 1.0 * sum / n << "\n";
    return 0;
}


```
