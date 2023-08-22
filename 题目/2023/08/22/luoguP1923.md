[P1923 【深基9.例4】求第 k 小的数](https://www.luogu.com.cn/problem/P1923)

> stl 

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0;i < n;++i) cin >> a[i];
    nth_element(a.begin(),a.begin() + k,a.end());
    cout << a[k] << "\n";

    return 0;
}
```
