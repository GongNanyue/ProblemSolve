[P3916 图的遍历](https://www.luogu.com.cn/problem/P3916)

建反图 链式前向星写法

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx, ans[N];

void add(int a, int b) {
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

void dfs(int u, int p) {
    ans[u] = p;
    for (int i = h[u]; i != 0; i = ne[i]) {
        int v = e[i];
        if (ans[v] == 0) dfs(v, p);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(b, a);
    }

    for (int i = n; i >= 1; --i) {
        if (ans[i] == 0) dfs(i, i);
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];

    return 0;
}
```
