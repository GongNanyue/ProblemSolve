[P1226 【模板】快速幂 | 取余运算](https://www.luogu.com.cn/problem/P1226)

> [快速幂](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E5%AD%A6/%E5%BF%AB%E9%80%9F%E5%B9%82.md)

```cpp
#include <bits/stdc++.h>
using ll = long long;

ll qmi(ll a,ll b,ll m){
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}


int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    ll a,b,m;
    std::cin >> a >> b >> m;
    std::cout << a << "^" << b << " mod " << m << "=" << qmi(a,b,m) << "\n";

    return 0;
}
```
