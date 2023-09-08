[P3128 [USACO15DEC] Max Flow P](https://www.luogu.com.cn/problem/P3128)

> 树上差分


```cpp
#include <bits/stdc++.h>
using namespace std;

const int N =5e4+10;
int n,k,ans;
vector<int> adj[N];

int d[N];// 点权后缀和差分数组

int fa[N],sz[N],dpt[N],hsn[N],top[N];

void dfs1(int u,int p){
    fa[u] = p;
    sz[u] = 1;
    dpt[u] = dpt[p] + 1;
    for(auto v : adj[u]) if(v != p){
        dfs1(v,u);
        sz[u] += sz[v];
        if(sz[v] > sz[hsn[u]]) hsn[u] = v;
    }
}

void dfs2(int u,int tp){
    top[u] = tp;
    if(hsn[u] == 0) return;
    dfs2(hsn[u],tp);
    for(auto v : adj[u]) if(v != fa[u] && v != hsn[u]){
        dfs2(v,v);
    }
}

int lca(int u,int v){
   while(top[u] != top[v]){
        if(dpt[top[u]] < dpt[top[v]]) swap(u,v);
        u = fa[top[u]];
   }
   return dpt[u] < dpt[v] ? u : v;
}
void update(int u,int v,int k){
    // 在 u -> v 的路径上的点权增加k
    int l = lca(u,v);
    
    d[u] += k;
    d[v] += k;
    d[l] -= k;
    d[fa[l]] -= k;
}
void dfs3(int u,int p){
    for(auto v : adj[u]) if(v != p){
        dfs3(v,u);
        d[u] += d[v];
    }
    ans = max(ans,d[u]);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n - 1;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,1);

    for(int i = 0;i < k;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        update(x,y,1);
    }
    dfs3(1,0);
    printf("%d\n",ans);
    return 0;
}
```

