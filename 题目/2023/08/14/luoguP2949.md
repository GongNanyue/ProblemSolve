[P2949 [USACO09OPEN] Work Scheduling G](https://www.luogu.com.cn/problem/P2949)

> 贪心

反悔贪心，按照截止时间从小到大排序，如果当前的已经超过了截止时间，考虑是不是可以通过更换来增加利润



```cpp
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;


struct wk {
    int d{};
    int p{};

    bool operator<(const wk &rhs) const {
        return std::tie(d, p) < std::tie(rhs.d, rhs.p);
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<wk> w(n);
    for (int i = 0; i < n; ++i)
        std::cin >> w[i].d >> w[i].p;
    std::sort(w.begin(), w.end());
    std::priority_queue<int,std::vector<int>,std::greater<>> q;
    ll ans{0};
    ll cnt{0};
    for (int i = 0; i < n; ++i) {
        if (++cnt <= w[i].d) {
            ans += w[i].p;
            q.push(w[i].p);
        } else {
            --cnt;
            if (q.empty() || q.top() >= w[i].p) continue;
            ans += w[i].p - q.top();
            q.pop();
            q.push(w[i].p);
        }
    }

    std::cout << ans << "\n";
    return 0;
}

```
