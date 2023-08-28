[P2419 [USACO08JAN] Cow Contest S](https://www.luogu.com.cn/problem/P2419)

求传递闭包，并且与其他所有奶牛都有关系的奶牛排名是确定的

```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        A[a][b] = 1;
    }


    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                A[i][j] |= A[i][k] & A[k][j];
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int flag = 1;
        for (int j = 1; j <= n; ++j)
            if (i != j && !(A[i][j] | A[j][i])) {
                flag = 0;
                break;
            }
        cnt += flag;
    }

    cout << cnt << "\n";
    return 0;
}

```
