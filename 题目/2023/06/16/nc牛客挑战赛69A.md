[lasing](https://ac.nowcoder.com/acm/contest/58833/A)

```cpp
#include <bits/stdc++.h>

using ll = long long;
const ll mod = 998244353;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

ll rev(ll a, ll m) {
    ll x, y;
    exgcd(a, m, x, y);
    while (x < 0)x += m;
    return x;
}


ll A(ll n, ll m) {
    ll res = 1;
    for (ll i = n - m + 1; i <= n; ++i)
        res = (res * i) % mod;
    return res;
}

ll C(ll n, ll m) {
    ll res = A(n, m);
    for (ll i = 2; i <= m; ++i)
        res = (res * rev(i, mod)) % mod;
    return res;
}

int main() {

    ll n;
    std::cin >> n;
    ll res = A(n, n);
    ll rest = 0;
    rest = (rest + C(n,2) * 1) % mod;
    rest= (rest + C(n,3) * 2) % mod;
    std::cout << (res - rest - 1+ mod) % mod << "\n";


    return 0;
}

```
