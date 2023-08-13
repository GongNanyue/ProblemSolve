[B3694 数列离散化](https://www.luogu.com.cn/problem/B3694)

> [离散化](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%9D%82%E9%A1%B9/%E7%A6%BB%E6%95%A3%E5%8C%96.md)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    for(cin >> T;T;T--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &v : a) cin >> v;
        vector<int> b = a;
        
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        
        for(auto v : a){
            cout << lower_bound(b.begin(),b.end(),v) - b.begin() + 1 << " ";
        }
        puts("");
    }
    return 0;
}
```
