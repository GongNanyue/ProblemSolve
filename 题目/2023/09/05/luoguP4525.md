[P4525 【模板】自适应辛普森法 1](https://www.luogu.com.cn/problem/P4525)

> 数值积分

```cpp
#include <bits/stdc++.h>
using namespace std;


double simpson(double f(double), double l, double r) {
    // 朴素辛普森积分
    return (f(l) + f(r) + 4 * f((l + r) / 2)) * (r - l) / 6;
}

double sim(double f(double), double s, double l, double r, double eps) {
    // 自适应辛普森积分
    double mid = (l + r) / 2;
    double s1 = simpson(f, l, mid);
    double s2 = simpson(f, mid, r);
    if (abs(s - s1 - s2) < 15 * eps) return s1 + s2;
    else return sim(f, s1, l, mid, eps / 2) + sim(f, s2, mid, r, eps / 2);
}

double l, r, a, b, c, d;

double fun1(double x) {
    return (c * x + d) / (a * x + b);
}

int main() {
    cin >> a >> b >> c >> d >> l >> r;

    cout << fixed << setprecision(6)
         << sim(fun1, simpson(fun1, l, r), l, r, 1e-7);
    return 0;
}
```
