```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e5 + 10;
ll n, m, a[N], sm[4 * N], lz[4 * N];
auto lc = [](ll u) { return 2 * u; };
auto rc = [](ll u) { return 2 * u + 1; };

void add_u(ll u, ll ul, ll ur, ll k) {
    sm[u] += (ur - ul + 1) * k;
    lz[u] += k;
}

void down(ll u, ll ul, ll ur) {
    if (lz[u]) {
        ll mid = (ul + ur) / 2;
        add_u(lc(u), ul, mid, lz[u]);
        add_u(rc(u), mid + 1, ur, lz[u]);
        lz[u] = 0;
    }
}

void up(ll u) {
    sm[u] = sm[lc(u)] + sm[rc(u)];
}

void build(ll u, ll ul, ll ur) {
    if (ul == ur) {
        sm[u] = a[ul];
    } else {
        ll mid = (ul + ur) / 2;
        build(lc(u), ul, mid);
        build(rc(u), mid + 1, ur);
        up(u);
    }
}

ll query_range(ll u, ll ul, ll ur, ll l, ll r) {
    if (ur < l || ul > r) return 0;
    if (l <= ul && ur <= r) return sm[u];
    ll mid = (ul + ur) / 2;
    down(u, ul, ur);
    return query_range(lc(u), ul, mid, l, r) + query_range(rc(u), mid + 1, ur, l, r);
}

void add_range(ll u, ll ul, ll ur, ll l, ll r, ll k) {
    if (ur < l || ul > r) return;
    if (l <= ul && ur <= r) {
        add_u(u, ul, ur, k);
        return;// 尤其注意要return 不然会死循环
    }
    ll mid = (ul + ur) / 2;
    down(u, ul, ur);
    add_range(lc(u), ul, mid, l, r, k);
    add_range(rc(u), mid + 1, ur, l, r, k);
    up(u);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            add_range(1, 1, n, x, y, k);
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            cout << query_range(1, 1, n, x, y) << "\n";
        }
    }


    return 0;
}
```
