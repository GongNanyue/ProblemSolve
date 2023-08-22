[B3715 分解质因子 2](https://www.luogu.com.cn/problem/B3715)

> 算数基本定理

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        for(ll i = 2;i * i <= n;++i){
            while (n % i == 0){
                cout << i << " ";
                n /= i;
            }
        }
        if(n > 1) cout << n;
        cout << "\n";
    }

    return 0;
}

```
