[P1002 [NOIP2002 普及组] 过河卒](https://www.luogu.com.cn/problem/P1002)

> [动态规划](https://github.com/GongNanyue/ProblemSolve/tree/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92)

```cpp
#include <bits/stdc++.h>

int bx, by, hx, hy;
const int N = 22;
using ll = long long;
bool block[N][N];
ll cnt[N][N];

bool inBound(int x, int y) {
    return 0 <= x && x <= bx && 0 <= y && y <= by;
}


int main() {

    std::cin >> bx >> by >> hx >> hy;
    {
        int dx[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
        int dy[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
        for (int i = 0; i < 9; ++i)
            if (inBound(hx + dx[i], hy + dy[i]))
                block[hx + dx[i]][hy + dy[i]] = true;
    }

    cnt[0][0] = 1;
    for (int i = 0; i <= bx; ++i)
        for (int j = 0; j <= by; ++j) {
            if (!block[i][j]) {
                if (inBound(i - 1, j))
                    cnt[i][j] += cnt[i - 1][j];
                if (inBound(i, j - 1))
                    cnt[i][j] += cnt[i][j - 1];
            }
        }

    std::cout << cnt[bx][by] << "\n";
    return 0;
}

```
