[P1102 A-B 数对](https://www.luogu.com.cn/problem/P1102)

> 二分

```cpp
#include <bits/stdc++.h>
using ull = unsigned long long;
int n, c;

int main() {
    std::cin >> n >> c;
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) std::cin >> A[i];
    std::sort(A.begin(),A.end());


    ull ans = 0;
    for(int i = 1;i < n;++i){
        int a = A[i],b = a - c;
        auto pit = std::equal_range(A.begin(),A.begin() + i + 1,b);
        ans += pit.second - pit.first;
    }
    std::cout << ans << "\n";

    return 0;
}
```
