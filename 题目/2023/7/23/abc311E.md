[E - Defect-free Squares](https://atcoder.jp/contests/abc311/tasks/abc311_e)

> [dp](https://github.com/GongNanyue/ProblemSolve/tree/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92)

dp[i][j] 是以(i,j)为右下角的最大正方形的边长

dp[i][j]在(i,j)不是洞的前提下分别往dp[i-1][j], dp[i][j-1], dp[i-1][j-1] 三个方向增长 
并且只能增长最少的边长

```cpp
#include <bits/stdc++.h>

using ll = long long;
const ll N = 3010;
ll h,w,n;
bool M[N][N];
ll dp[N][N];

int main(){
    std::cin >> h >> w >> n;
    while (n--){
        ll x,y;
        std::cin >> x >> y;
        M[x][y] = true;
    }

    ll cnt = 0;
    for(int i = 1;i <= h;++i)
        for(int j = 1;j <= w;++j){
            if(M[i][j]) continue;
            dp[i][j] = std::min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
            cnt += dp[i][j];
        }

    std::cout << cnt << "\n";


    return 0;
}
```
