[B3611 【模板】传递闭包](https://www.luogu.com.cn/problem/B3611)


Floyd-Wallshall 求传递闭包闭包算法动态规划思想

k = 0表示经过0这个中间点可以到达的范围

k = 1表示经过0,1这两个点可以到达的范围

...

k = n - 1表示经过0,1,2...n-1这些点可以到达的范围


```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    // Floyd-Wallshall 求闭包算法
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (A[i][k] && A[k][j])
                    A[i][j] = 1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << A[i][j] << " \n"[j == n - 1];
    return 0;
}
```
