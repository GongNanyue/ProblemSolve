[B3716 分解质因子 3](https://www.luogu.com.cn/problem/B3716)

> 线性筛

```cpp
#include <bits/stdc++.h>
const int N = 1e8 + 10;
std::bitset<N> vis;
int mn[N], ps[N / 10];
//小于x的质数的个数~=x/ln(x)

void get_primes() {
    for (int i = 2; i < N; ++i) {
        if (!vis[i]) { ps[++ps[0]] = i; mn[i] = i;}
        for (int j = 1; j <= ps[0] && ps[j] <= N / i; ++j) {
            mn[ps[j] * i] = ps[j];
            vis[ps[j] * i] = true;
            if (i % ps[j] == 0) break;
        }
    }
}


int main() {
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    get_primes();
    while (t--){
        int x;
        std::cin >> x;
        int sum = 0;
        while (x!=1){
            sum ^= mn[x];
            x /= mn[x];
        }
        std::cout << sum << "\n";
    }

    return 0;
}

```
