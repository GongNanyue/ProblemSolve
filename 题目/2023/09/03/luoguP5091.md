[P5091 【模板】扩展欧拉定理](https://www.luogu.com.cn/problem/P5091)

> 扩展欧拉定理

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll qpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b = b >> 1;
    }
    return res;
}

ll eular(ll n) {
    //求出欧拉函数φ(n)
    ll res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) res = res / n * (n - 1);
    return res;
}

ll eular_read(ll phim) {
    // 读取b并且进行欧拉降幂
    // phim = φ(m)

    ll b = 0;
    bool f = false;
    char ch;
    while (!isdigit(ch = getchar()));
    while (isdigit(ch)) {
        b = b * 10 + ch - '0';
        if (b >= phim) f = true;
        b = b % phim;
        ch = getchar();
    }
    return b + f * phim;
}

ll eular_drop(const string &bs, ll phim) {
    // 对b在mod m的情况下进行欧拉降幂
    ll b = 0;
    bool f = false;
    for (char ch: bs) {
        b = b * 10 + ch - '0';
        if (b >= phim) f = true;
        b %= phim;
    }
    return b + f * phim;
}

int main() {
    ll a, m;
    scanf("%lld%lld", &a, &m);
    ll b = eular_read(eular(m));
    printf("%lld", qpow(a, b, m));

    return 0;
}
```
