[P3370 【模板】字符串哈希](https://www.luogu.com.cn/problem/P3370)

> 字符串哈希

```cpp

#include <bits/stdc++.h>

using ll = long long;

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE1 = 131;
const int BASE2 = 13331;


auto get_hash(const std::string &s) {
    int h1 = 0, h2 = 0;
    for (auto c: s) {
        h1 = (ll(h1) * BASE1 + c) % MOD1;
        h2 = (ll(h2) * BASE2 + c) % MOD2;
    }
    return std::make_pair(h1,h2);
}


int main() {
    int n; std::cin >> n;
    std::vector<std::pair<int,int>> pa;
    int cnt = 0;
    while (n--){
        std::string s;
        std::cin >> s;
        auto h0 = get_hash(s);
        bool flag = true;
        for(auto h : pa){
            if(h == h0){
                flag = false;
                break;
            }
        }
        if(flag) {
            pa.push_back(h0);
            cnt++;
        }
    }

    std::cout << cnt << "\n";
    return 0;
}
```
