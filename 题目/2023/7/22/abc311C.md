[C - Find it!](https://atcoder.jp/contests/abc311/tasks/abc311_c)

```cpp
#include <bits/stdc++.h>
int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n+1);
    std::vector<bool> vis(n+1);
    for(int i = 1;i <= n;++i) std::cin >> a[i];


    // 使用i来找到一个环的起点
    int i = 1;
    while(!vis[i]){
        vis[i] = true;
        i = a[i];
    }

    std::vector<int> ans;
    ans.push_back(i);
    int j = a[i];
    while(j != i){
        ans.push_back(j);
        j = a[j];
    }

    std::cout << ans.size() << "\n";
    for(int k = 0;k < ans.size();++k)
        std::cout << ans[k] << " \n"[k == ans.size()-1];

    return 0;
}
```
