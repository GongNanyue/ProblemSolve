[P2822 [NOIP2016 提高组] 组合数问题](https://www.luogu.com.cn/problem/P2822)

> 组合 前缀和

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10;
int C[N][N], S[N][N];
int n, m, k;

void showC(int nn) {
    cout << "\n";
    for (int i = 0; i <= nn; ++i)
        for (int j = 0; j <= nn; ++j)
            cout << C[i][j] << " \n"[j == nn];
    cout << "----\n";
}
void showS(int nn) {
    cout << "\n";
    for (int i = 0; i <= nn; ++i)
        for (int j = 0; j <= nn; ++j)
            cout << S[i][j] << " \n"[j == nn];
    cout << "----\n";
}

int main() {
    int t;
    cin >> t >> k;

    // cout << k << "\n";
    C[0][0] = 1;
    for (int i = 1; i <= N - 1; ++i)
        for (int j = 0; j <= i; ++j) {
            C[i][j] = C[i - 1][j];
            if (j - 1 >= 0) C[i][j] += C[i - 1][j - 1];
            C[i][j] = C[i][j] % k;
        }
    for (int i = 0; i <= N - 1; ++i)
        for (int j = i + 1; j <= N - 1; ++j)
            C[i][j] = -1;

//    showC(10);

    for (int i = 0; i <= N - 1; ++i)
        for (int j = 0; j <= N - 1; ++j) {
            S[i][j] = (C[i][j] == 0);
            if (i - 1 >= 0) S[i][j] += S[i - 1][j];
            if (j - 1 >= 0) S[i][j] += S[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0) S[i][j] -= S[i - 1][j - 1];
        }

//    showS(10);

    while (t--) {
        cin >> n >> m;
        cout << S[n][m] << "\n";
    }
    return 0;
}
```
