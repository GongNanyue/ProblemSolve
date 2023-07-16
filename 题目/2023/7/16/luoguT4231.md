[P4231 三步必杀](https://www.luogu.com.cn/problem/P4231)

> [差分](https://github.com/GongNanyue/ProblemSolve/blob/main/%E7%AE%97%E6%B3%95%E5%9F%BA%E7%A1%80/%E5%89%8D%E7%BC%80%E5%92%8C%E5%B7%AE%E5%88%86.md)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    vector<ll> d1(n + 5), d2(n + 5);
    while (m--) {
        int l, r, s, e;
        cin >> l >> r >> s >> e;
        int dc = (e - s) / (r - l);
        d2[l + 1] += dc;
        d2[r + 1] -= dc;
        d1[l] += s;
        d1[r + 1] -= e;
    }

    for (int i = 1; i <= n; ++i)
        d2[i] += d2[i - 1];
    for (int i = 1; i <= n; ++i)
        d1[i] += d1[i - 1] + d2[i];
    ll sum = 0;
    ll mx = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, d1[i]);
        sum = sum ^ d1[i];
    }
    cout << sum << " " << mx << "\n";
    return 0;
}

```
