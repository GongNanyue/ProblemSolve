[P3865 【模板】ST 表](https://www.luogu.com.cn/problem/P3865)

> [st表](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/ST%E8%A1%A8.md)


```cpp
#include <bits/stdc++.h>

int n,m;

int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);

    std::cin >> n >> m;
    std::vector<int> a(n+1);
    std::vector<std::vector<int>> st(20,std::vector<int>(n+1));

    for(int i = 1;i <= n;++i) {
        std::cin >> a[i];
        st[0][i] = a[i];
    }

    for(int p = 1;p < 20;++p){
        for(int l = 1;l <= n;++l){
            int r = l + (1<<(p)) - 1;
            if(r > n) break;
            int mid = l + (1<<(p-1));
            st[p][l] = std::max(st[p-1][l],st[p-1][mid]);
        }
    }

    while(m--){
        int l,r; std::cin >> l >> r;
        int len = r - l + 1;
        int loglen = std::log2(len);

        std::cout << std::max(st[loglen][l],st[loglen][r - (1<<(loglen)) + 1]) << "\n";
    }

    return 0;
}
```
