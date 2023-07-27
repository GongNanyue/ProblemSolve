[P1032 [NOIP2002 提高组] 字串变换](https://www.luogu.com.cn/problem/P1032)

> [bfs](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%90%9C%E7%B4%A2/%E5%B9%BF%E5%BA%A6%E4%BC%98%E5%85%88%E6%90%9C%E7%B4%A2.md)


```cpp
#include <bits/stdc++.h>



std::string a,b;
std::vector<std::pair<std::string,std::string>>mp;

struct state{
    std::string s;
    int pace;

};


void bfs(){
    std::unordered_set<std::string> vis;
    std::queue<state> Q;
    Q.emplace(state{a,0});
    vis.insert(a);

    while(!Q.empty()){
        auto [u,pace] = Q.front();Q.pop();
        for(auto [p,q] : mp){
            for(int i = 0;i < u.size();++i){
                if(u.substr(i,p.size()) == p){
                    std::string v = u.substr(0,i) + q + u.substr(i + p.size(),u.size());
                    if(!vis.count(v)){
                        if(v == b && pace <= 9){
                            std::cout << pace + 1 << "\n";
                            exit(0);
                        }
                        if(pace <= 9){
                            Q.emplace(state{v,pace+1});
                            vis.insert(v);
                        }
                    }
                }
            }
        }
    }
}



int main(){
    std::cin >> a >> b;
    std::string p,q;
    while(std::cin >> p >> q){
        mp.push_back({p,q});
    }

    bfs();
    std::cout << "NO ANSWER!\n";



    return 0;
}

```
