[P4306 [JSOI2010] 连通数](https://www.luogu.com.cn/problem/P4306)


使用bitset进行优化

```cpp
#include <bits/stdc++.h>
using namespace std;

bitset<2010> M[2010];
int n;

void show() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cout << M[i][j] << " \n"[j == n];
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            char c;
            cin >> c;
            if (c == '0') M[i][j] = false;
            else if (c == '1')M[i][j] = true;
            if (i == j) M[i][j] = true;
        }

    // show();

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            if (M[i][k])
                M[i] = M[i] | M[k];

    int cnt =0;
    for(int i = 1;i <= n;++i)
        cnt += M[i].count();

    cout << cnt << "\n";



    return 0;
}
```
