[P6510 奶牛排队](https://www.luogu.com.cn/problem/P6510)

> [单调栈](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E5%8D%95%E8%B0%83%E6%A0%88.md)



维护各个前缀最大最小的单调栈
枚举右端点r从1到n
如果有这样一个区间第一个严格最小，最后一个最大
那么左端点l满足l是r前缀的最小单调栈中 并且a[l]要大于最大单调栈r之前的值


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

int n;
std::vector<int> a;
std::deque<int> mn,mx;
int main(){
    std::cin >> n;
    a.assign(n + 1,0);
    for(int i = 1;i <= n;++i){ 
        std::cin >> a[i];
    }


    int ans = 0;
    for(int i = 1;i <= n;++i){
        int r = i;
        while(!mn.empty() && a[mn.back()] >= a[i])
            mn.pop_back();
        
        
        while(!mx.empty() && a[mx.back()] < a[i])
            mx.pop_back();
        


        auto k = std::upper_bound(mn.begin(),mn.end(),mx.size() == 0 ? 0 : mx.back());
        if(k != mn.end()){
            ans = std::max(ans,i - *k + 1);
        }

        mn.push_back(i),mx.push_back(i);
        //mn最后push_back是因为区间不能长度是1
        //mx最后push_back是因为要找r之前的那一个最大值
    }
    std::cout << ans << "\n";

    return 0;
}
```
