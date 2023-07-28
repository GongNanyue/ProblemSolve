[P1120 小木棍](https://www.luogu.com.cn/problem/P1120)

> dfs
> 剪枝

```cpp
#include <bits/stdc++.h>

const int N = 70;
int n;
int sum = 0,max = 0;
const int MAXA = 50 + 3;
int H[MAXA];

bool dfs(int step, int left, int pre, int len){
    if(step == n + 1){
        return true;
    }

    //step 正在拼第几个长木棍
    //left 现在正在拼的木棍还需要的长度
    //pre 拼这个木棍时上一次用的短木棍的长度 如果跳转下一个木棍设置为max
    //len 长木棍的目标长度
    for(int i = std::min({max,left,pre});i > 0;--i){
        if(H[i]){
            H[i]--;bool f;
            
            if(i == left){//当选中的小木棍刚好可以是剩下所需长木棍的长度
                f = dfs(step + 1, len, max, len);
                H[i]++;
                return f;
            }

            if(left == len){//重新拼一个新木棍
                f = dfs(step + 1, len - i, i, len);
                H[i]++;
                return f;
            }

            f = dfs(step + 1, left - i, i, len);
            H[i]++;
            if(f) return true;
        }
    }
    return false;//在尝试所有的可能后都不行返回false
}

int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    std::cin >> n;
    
    for(int i = 0;i < n;++i){
        int val; std::cin >> val;
        H[val]++;
        sum += val;
        max = std::max(max,val);
    }

    for(int l = max; ;l++){
        if(sum % l == 0)
            if(dfs(1,l,max,l)){
                std::cout << l << "\n";
                exit(0);
            }    
    }

    return 0;
}
```
