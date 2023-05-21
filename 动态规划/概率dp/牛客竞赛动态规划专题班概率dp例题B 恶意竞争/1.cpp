#include <bits/stdc++.h>
using namespace std;
#ifndef  ONLINE_JUDGE
const int N = 3;
#else
const int N = 1e3 + 10;
#endif

int n, s;
double f[N][N];
//f[i][j] 表示已经发现了i个子系统 j类bug 到达目标所需要的期望天数
//f[n][s] = 0;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s;

    for (int i = s; i >= 0; --i)
        for (int j = n; j >= 0; --j) {
            double p1 = (double) i * j / s / n,
                    p2 = (double) (s - i) * j / s / n,
                    p3 = (double) i * (n - j) / s / n,
                    p4 = (double) (s - i) * (n - j) / s / n;

            if (i + 1 <= s)
                f[i][j] += p2 * f[i + 1][j];
            if (j + 1 <= n)
                f[i][j] += p3 * f[i][j + 1];
            if (i + 1 <= s && j + 1 <= n)
                f[i][j] += p4 * f[i + 1][j + 1];
            if (i != s || j != n) f[i][j] = (f[i][j] + 1.0) / (1.0 - p1);
        }


    cout << setprecision(4) << fixed
         << f[0][0] << "\n";


}
