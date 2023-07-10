[P1122 最大子树和](https://www.luogu.com.cn/problem/P1122)https://www.luogu.com.cn/problem/P1122

> [树形dp](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E6%A0%91%E5%BD%A2dp.md)

```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adjlst;
vector<int> values;
vector<int> dp;

void dfs(int u, int p) {
    dp[u] = values[u];
    for (auto v: adjlst[u]) {
        if (v == p) continue;
        dfs(v, u);

        dp[u] += max(dp[v],0);
    }
}


int main() {
    cin >> n;
    values.assign(n + 1, 0);
    adjlst.assign(n + 1, vector<int>());
    dp.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> values[i];
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adjlst[x].push_back(y);
        adjlst[y].push_back(x);
    }

    dfs(1,1);

    int mx = -INT_MAX;
    for (int i = 1; i <= n; ++i)
        mx = max(mx, dp[i]);
    cout << mx << "\n";
    return 0;
}
```
