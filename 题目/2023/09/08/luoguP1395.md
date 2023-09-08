[P1395 会议](https://www.luogu.com.cn/problem/P1395)

> 树的重心

树中所有点到某个点的距离和中，到重心的距离和是最小的；如果有两个重心，那么到它们的距离和一样

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10;

int n,sm/*距离和*/;
vector<int> adj[N];
int sz[N],mx[N],dist[N];

void dfs(int u,int p){
    sz[u] = 1;
    for(auto v : adj[u]) if(v != p){
        dfs(v,u);
        sz[u] += sz[v];
        mx[u] = max(mx[u],sz[v]);
    }
    mx[u] = max(mx[u],n - sz[u]);
}

void bfs(int u){
    memset(dist,0x3f,sizeof dist);
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        sm += dist[u];
        for(auto v : adj[u]) 
            if(dist[v] == 0x3f3f3f3f){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    for(int i = 0;i < n - 1;++i){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y),adj[y].push_back(x);
    }
    dfs(1,0);


    int u = 1;
    for(int i = 2;i <= n;++i)
        if(mx[i] < mx[u]) u = i;
    bfs(u);

    cout << u << " " << sm << "\n";
    return 0;
}
```
