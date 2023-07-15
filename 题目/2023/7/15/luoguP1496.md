[P1496 火烧赤壁](https://www.luogu.com.cn/problem/P1496)

> [离散化](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%9D%82%E9%A1%B9/%E7%A6%BB%E6%95%A3%E5%8C%96.md)
> [差分](https://github.com/GongNanyue/ProblemSolve/blob/main/%E7%AE%97%E6%B3%95%E5%9F%BA%E7%A1%80/%E5%89%8D%E7%BC%80%E5%92%8C%E5%B7%AE%E5%88%86.md)

```cpp
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n;

struct seg {
    int l, r; //[l,r)
    seg(int a = 0, int b = 0) : l(a), r(b) {}
};


int main() {
    cin >> n;
    vector<seg> sgs(n);
    vector<int> ps;
    for (int i = 0; i < n; ++i) {
        cin >> sgs[i].l >> sgs[i].r;
        ps.push_back(sgs[i].l);
        ps.push_back(sgs[i].r);
    }


    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    unordered_map<int, int> mp;// real -> hash
    for (int i = 0; i < ps.size(); ++i)
        mp[ps[i]] = i;


    vector<int> d(ps.size() + 1);
    for (const auto &s: sgs) {
        auto l = s.l, r = s.r;
        auto lidx = mp[l], ridx = mp[r];
        d[lidx + 1] += 1;
        d[ridx + 1] -= 1;
    }

    vector<int> s(ps.size() + 1);
    for (int i = 1; i <= ps.size(); ++i) {
        s[i] = s[i - 1] + d[i];
    }
    int ans = 0;
    for (int i = 1; i <= ps.size(); ++i) {
        if (s[i] > 0)
            ans += ps[i] - ps[i - 1];
    }
    cout << ans << "\n";
    return 0;

}
```
