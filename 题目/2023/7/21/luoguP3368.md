[P3368 【模板】树状数组 2](https://www.luogu.com.cn/problem/P3368)

> [树状数组](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84.md)
> [差分](https://github.com/GongNanyue/ProblemSolve/blob/main/%E7%AE%97%E6%B3%95%E5%9F%BA%E7%A1%80/%E5%89%8D%E7%BC%80%E5%92%8C%E5%B7%AE%E5%88%86.md)

```cpp
#include <bits/stdc++.h>
template<typename T>
std::ostream &operator<<(std::ostream &os,const std::vector<T> &vec){
    os << "vec{";
    for(size_t i = 0;i < vec.size();++i)
        os << vec[i] << ",}"[i == vec.size() - 1];
    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os,const std::deque<T> dq){
    os << "dq{";
    for(size_t i = 0;i < dq.size();++i)
        os << dq[i] << ",}"[i == dq.size() - 1];
    return os;
}

const int N = 5e5+10;
int n,m;
int a[N],c[N];

int ask(int x){//求a[1...x]的和
    int y = 0;
    for(;x;x-=x&-x) y+=c[x];
    return y;
}

void add(int x,int y){//在a[x]上加上y
    for(;x<=n;x+=x&-x) c[x] += y;
}
int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1;i <= n;++i){
        std::cin >> a[i];
        add(i,a[i]-a[i-1]);
        // 树状数组中存放的是原来数组的差分数组
    }

    while(m--){
        int op; std::cin >> op;
        if(op == 1){
            int x,y,k; std::cin >> x >> y >> k;
            add(x,k),add(y + 1,-k);
            // 在d[x]加k 在d[y + 1]减k
        }else if(op == 2){
            int x; std::cin >> x;
            std::cout << ask(x) << "\n";
            // ask(x)刚好是询问树状数组的前k个和 正好是原数组a[x]
        }
    }


    return 0;
}
```
