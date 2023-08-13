[P1247 取火柴游戏](https://www.luogu.com.cn/problem/P1247)

> [Nim游戏](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E5%AD%A6/%E5%8D%9A%E5%BC%88%E8%AE%BA/%E5%85%AC%E5%B9%B3%E7%BB%84%E5%90%88%E6%B8%B8%E6%88%8F/Nim%E6%B8%B8%E6%88%8F.md) 

```cpp
#include <bits/stdc++.h>

const int N = 500010;
int n;
int a[N];

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    int s = 0;
    for (int i = 1; i <= n; ++i)
        s = s ^ a[i];

    if (s == 0)
        std::cout << "lose\n";
    else {
        for (int i = 1; i <= n; ++i) {
            if ((a[i] ^ s) < a[i]) { //找到第一个和s最高的1位置相同的数a[i]，满足 a[i] ^ s < a[i]
                std::cout << a[i] - (a[i] ^ s) << " " << i << "\n";
                a[i] = a[i] ^ s;
                break;
            }
        }
        for (int i = 1; i <= n; ++i)
            std::cout << a[i] << " \n"[i == n];
    }

    return 0;
}

```
