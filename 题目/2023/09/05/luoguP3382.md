[P3382 【模板】三分法](https://www.luogu.com.cn/problem/P3382)

> 三分

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Poly {
    vector<double> cof;//coefficient

    explicit Poly(int n) {// 最高次数是n次
        cof.resize(n + 1);
    }

    double operator()(double x) {
        double res = 0;
        for (int i = 0; i < cof.size(); ++i)
            res += pow(x, i) * cof[i];
        return res;
    }

    double findMax(double l, double r, double eps) {
        // 找到极大值的根
        while (r - l > eps) {
            double mid = (l + r) / 2;
            double lmid = mid - eps;
            double rmid = mid + eps;
            if ((*this)(lmid) > (*this)(rmid))
                r = mid;
            else
                l = mid;
        }
        return (l + r) / 2;
    }

    double findMin(double l, double r, double eps) {
        // 找到极小值的根
        while (r - l > eps) {
            double mid = (l + r) / 2;
            double lmid = mid - eps;
            double rmid = mid + eps;
            if ((*this)(lmid) < (*this)(rmid))
                r = mid;
            else
                l = mid;
        }
        return (l + r) / 2;
    }
};

double eps = 1e-7;

int main() {
    int n;
    double l, r;
    cin >> n >> l >> r;
    Poly f(n);
    for (int i = n; i >= 0; --i) cin >> f.cof[i];
    cout << f.findMax(l, r, eps);

    return 0;
}
```
