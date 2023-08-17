[P2840 纸币问题 2](https://www.luogu.com.cn/problem/P2840)

> dp


```cpp
#include <bits/stdc++.h>
using ll = long long;
ll mod = 1e9+7;


int main() {
    ll n, w;
    std::cin >> n >> w;
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<ll> f(w + 1);
    f[0] = 1;
    for(int i = 1;i <= w;++i){
        for(auto v : a){
            if(i - v >= 0)
                f[i] = (f[i] + f[i - v]) % mod;
        }
    }
    std::cout << f[w] << "\n";
    return 0;
}
```
