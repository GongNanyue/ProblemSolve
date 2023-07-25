[D - Peaceful Teams](https://atcoder.jp/contests/abc310/tasks/abc310_d)

> [dfs](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%90%9C%E7%B4%A2/%E6%B7%B1%E5%BA%A6%E4%BC%98%E5%85%88%E6%90%9C%E7%B4%A2.md)

```cpp
#include <bits/stdc++.h>

int n, t, m;
std::unordered_map<int, std::unordered_set<int>> occur;
std::vector<std::vector<int>> comb;
int ans = 0;

void dfs(int num) {
    if (num == n + 1) {
        if (comb.size() == t)
            ans++;
    } else {
        comb.push_back(std::vector<int>{num});
        dfs(num + 1);
        comb.pop_back();


        for (int i = 0; i < comb.size(); ++i) {
            bool in = true;
            for (int j = 0; j < comb[i].size(); ++j) {
                if (occur[num].count(comb[i][j]) == 1) {
                    in = false;
                    break;
                }
            }
            if (in) {
                comb[i].push_back(num);
                dfs(num + 1);
                comb[i].pop_back();
            }
        }
    }
}


int main() {
    std::cin >> n >> t >> m;
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        occur[a].insert(b), occur[b].insert(a);
    }

    comb.push_back(std::vector<int>{1});
    dfs(2);
    std::cout << ans << "\n";

    return 0;
}
```
