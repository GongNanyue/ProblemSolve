[B3717 组合数问题](https://www.luogu.com.cn/problem/B3717)


> 乘法逆元

$(x!)^{-1} \equiv ((x-1)!) ^ {-1} \times (x - 1)$

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p = 998244353;
const ll N = 5e6 + 10;
ll facinv[N], fac[N], inv[N];
// (x!)^-1     x!      x^-1

void get_invs() {
    inv[0] = -1, inv[1] = 1;
    fac[0] = fac[1] = 1;
    facinv[0] = facinv[1] = 1;
    for (int i = 2; i < N; ++i) {
        inv[i] = p - p / i * inv[p % i] % p;
        fac[i] = (fac[i-1] * i) % p;
        facinv[i] = (facinv[i - 1] * inv[i]) % p;
    }
}


int main() {
    get_invs();
    int t,n;
    cin >> t >> n;
    ll sum = 0;
    while (t--){
        ll n,m;
        cin >> n >> m;
        sum ^= ((fac[n] * facinv[m] % p) * facinv[n - m]) % p ;
    }
    cout << sum << "\n";

    return 0;
}

```
