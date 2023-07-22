[D - Grid Ice Floor](https://atcoder.jp/contests/abc311/tasks/abc311_d)

> [bfs](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%90%9C%E7%B4%A2/%E5%B9%BF%E5%BA%A6%E4%BC%98%E5%85%88%E6%90%9C%E7%B4%A2.md)

```cpp
#include <bits/stdc++.h>

using pii = std::pair<int,int>;
int n,m;
std::vector<std::string> M;
std::vector<std::vector<bool>> vis,pass;

int dx4[] = {1,0,-1,0};
int dy4[] = {0,-1,0,1};

int main(){
    std::cin >> n >> m;
    M.assign(n,std::string());
    vis.assign(n,std::vector<bool>(m,false));
    pass.assign(n,std::vector<bool>(m,false));
    for(int i = 0;i < n;++i) std::cin >> M[i];

    vis[1][1] = true;
    pass[1][1] = true;
    std::queue<pii> q;
    q.emplace(1,1);

    while(!q.empty()){
        auto [a,b] = q.front();q.pop();

        for(int i = 0;i < 4;++i){
            int x = a,y = b;
            while(M[x][y] == '.'){
                pass[x][y] = true;
                x += dx4[i];
                y += dy4[i];
            }
            x -= dx4[i];
            y -= dy4[i];
            if(!vis[x][y]){
                vis[x][y] = true;
                q.emplace(x,y);
            }
        }
    }

    int cnt = 0;
    for(int i = 0;i < n;++i)
        for(int j = 0;j < m;++j)
            if(pass[i][j])
                ++cnt;

    std::cout << cnt << "\n";
    return 0;
}
```
