[P1892 [BOI2003]团伙](https://www.luogu.com.cn/problem/P1892)

```cpp
#include <bits/stdc++.h>

const int N = 1010;
int n, m;

int leader[2 * N];

int findleader(int u) {
    return leader[u] == u ? u : leader[u] = findleader(leader[u]);
}

bool sameleader(int u, int v) {
    return findleader(u) == findleader(v);
}

void merge(int u, int v) {
    leader[findleader(u)] = findleader(v);
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= 2 * n; ++i) //下标从1开始
        leader[i] = i;

    for (int i = 0; i < m; ++i) {
        std::string rl;
        std::cin >> rl;
        int p, q;
        std::cin >> p >> q;
        if (rl == "F") {
            merge(p, q);
        } else if (rl == "E") {
            merge(p + n, q);
            merge(q + n,p); // 反集
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;++i){
        if(leader[i] == i)
            ++cnt;
    }
    std::cout << cnt << "\n";
    return 0;
}

```
