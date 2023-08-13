[P3374 【模板】树状数组 1](https://www.luogu.com.cn/problem/P3374)

> [树状数组](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84.md)


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
    memset(c + 1,0,sizeof(int) * n);

    for(int i = 1;i <= n;++i){
        int v;std::cin >> v;
        add(i,v);
    }

    while(m--){
        int op; std::cin >> op;
        if(op == 1){
            int x,k; std::cin >> x >> k;
            add(x,k);
        }else if(op == 2){
            int x,y; std::cin >> x >> y;
            std::cout << ask(y) - ask(x-1) << "\n";
        }
    }
    return 0;
}
```
