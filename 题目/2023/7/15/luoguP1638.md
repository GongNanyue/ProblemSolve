[P1638 逛画展](https://www.luogu.com.cn/problem/P1638)

> [双指针](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%9D%82%E9%A1%B9/%E5%8F%8C%E6%8C%87%E9%92%88.md)

```cpp
#include <bits/stdc++.h>

int n, m;
int main() {
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::map<int,int> mp;
    for (auto &v : a) std::cin >> v;
    int i = 0, j = 0, len = INT_MAX, cnt = 0;
    //[i,j)
    while(j < n && cnt < m){
        if(mp[a[j]] == 0)cnt++;
        mp[a[j]]++;
        j++;
    }
    len = j - i;
    int l = 0,r = j - 1;

    while(i < n && j < n){
        while(i < j && cnt == m){
            if(mp[a[i]] == 1)cnt--;
            mp[a[i]]--;
            i++;
        }
        if(cnt == m-1 && len > j - (i-1)){
            len = j - (i-1);
            l = i-1;
            r = j - 1;
        }
        while(j < n && cnt < m){
            if(mp[a[j]] == 0)++cnt;
            mp[a[j]]++;
            j++;
        }
        if(cnt == m && len > j - i){
            len = j - i;
            l = i;
            r = j - 1;
        }
    }
    std::cout << l + 1 << " " << r + 1 << "\n";
    return 0;
}

```
