[P1303 A*B Problem](https://www.luogu.com.cn/problem/P1303)

>  [高精度](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E5%AD%A6/%E9%AB%98%E7%B2%BE%E5%BA%A6.md)

```cpp
#include <bits/stdc++.h>


int main() {
    std::string a, b;
    std::cin >> a >> b;
    auto ra=a,rb = b;
    std::reverse(ra.begin(), ra.end());
    std::reverse(rb.begin(), rb.end());
    std::vector<int> res(a.size() * b.size());

    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j) {
            res[i + j] += (ra[i] - '0') * (rb[j] - '0');
            //第i位的数字乘上第j位的数字 放在第i+j位
        }

    for (int i = 0; i < res.size(); ++i) {
        if (res[i] >= 10) {
            res[i + 1] += res[i]/10;
            res[i] = res[i] % 10;
            //将要进位的数组往后放
        }
    }

    while (res.size() >= 2 && res.back() == 0)
        res.pop_back();   //去除前导零 但是不去除最后的0


    auto rres = res;
    std::reverse(rres.begin(), rres.end());


    for(auto val : rres)
        std::cout << val;

    return 0;
}
```
