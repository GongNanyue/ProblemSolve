[P4549 【模板】裴蜀定理](https://www.luogu.com.cn/problem/P4549)


> 裴蜀定理

广义裴蜀定理

$$
a_1 x_1 + a_2 x_2 + \ldots + a_n x_n = \gcd(a_1, a_2, \ldots, a_n) = d
$$

那么d是 $a_1 x_1 + a_2 x_2 + \ldots + a_n x_n$ 中的最小正整数
其他的数字都是d的倍数

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i < n;++i){
        int x;
        cin >> x;
        if(x < 0) x = -x;
        ans = gcd(ans,x);
    }
    cout << ans << "\n";

    return 0;
}
```
