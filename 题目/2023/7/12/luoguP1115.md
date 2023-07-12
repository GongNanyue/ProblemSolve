[P1115 最大子段和](https://www.luogu.com.cn/problem/P1115)

> [前缀和](https://github.com/GongNanyue/ProblemSolve/blob/main/%E7%AE%97%E6%B3%95%E5%9F%BA%E7%A1%80/%E5%89%8D%E7%BC%80%E5%92%8C%E5%B7%AE%E5%88%86.md)https://github.com/GongNanyue/ProblemSolve/blob/main/%E7%AE%97%E6%B3%95%E5%9F%BA%E7%A1%80/%E5%89%8D%E7%BC%80%E5%92%8C%E5%B7%AE%E5%88%86.md

##### 前缀和
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a,s,minS;
int main(){

    //freopen("in.txt","r",stdin);

    cin >> n;
    a.assign(n + 1, 0);
    s.assign(n + 1,0);
    minS.assign(n + 1,0);


    for(int i = 1;i <= n;++i){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        minS[i] = min(minS[i-1],s[i]);
    }


    int ans = INT_MIN;
    for(int i = 1;i <= n;++i){
        ans = max(ans, s[i] - minS[i-1]);
    }

    cout << ans << "\n";
    return 0;
}
```
