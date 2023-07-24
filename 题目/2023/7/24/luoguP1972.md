[P1972 [SDOI2009] HH的项链](https://www.luogu.com.cn/problem/P1972)

> [树状数组](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84.md)
> [离线](https://github.com/GongNanyue/ProblemSolve/tree/main/%E6%9D%82%E9%A1%B9/%E7%A6%BB%E7%BA%BF%E7%AE%97%E6%B3%95)

树状数组c[i]表示[1,i]中不相同的数字个数

询问[l,r]前缀和查询ask(r)-ask(l-1)

询问离线 按照r从小到大排序

p[x]表示数字x最后出现的位置 0表示还没找到过

对于若干个询问的区间[l,r]，如果他们的r都相等的话，那么项链中出现的同一个数字，一定是只关心出现在最右边的那一个的

那么不妨将计数的位置从p[a[r]] 转移到r，将前缀和ask(p[a[r]])删除 加上ask(r)

```cpp
#include <bits/stdc++.h>

const int N = 1e6+10;
int n,m;
int a[N],c[N],p[N];

void add(int x,int k){
    for(;x<=n;x+=x&-x) c[x] += k;
}

int ask(int x){
    int ans = 0;
    for(;x;x-=x&-x) ans += c[x];
    return ans;
}


struct query{
    int l,r,idx;

    bool operator<(const query &rhs) const{
        return r < rhs.r;
    }
};


int main(){
    std::cin >> n;
    for(int i = 1;i <= n;++i) std::cin >> a[i];

    std::cin >> m;
    std::vector<query>qs(m);
    for(int i = 0;i < m;++i){
        std::cin >> qs[i].l >> qs[i].r;
        qs[i].idx = i;
    }
    std::sort(qs.begin(),qs.end());

    std::vector<int> ans(m);

    int nextR = 1;
    for(auto [l,r,idx] : qs){

        for(int i = nextR;i <= r;++i){
            if(p[a[i]]){
                add(p[a[i]],-1),add(i,1);
                p[a[i]] = i;
            }else{
                add(i,1);
                p[a[i]] = i;
            }
        }

        ans[idx] = ask(r) - ask(l-1);
        nextR = r + 1;
    }

    for(auto v : ans)
        std::cout << v << "\n";


    return 0;
}
```
