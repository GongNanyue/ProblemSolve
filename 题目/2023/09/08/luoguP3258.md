[P3258 [JLOI2014] 松鼠的新家](https://www.luogu.com.cn/problem/P3258)

> 树上差分

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10;

int n,a[N];
vector<int> adj[N];
int fa[N],sz[N],hsn[N],dpt[N],top[N],dif[N];

void dfs1(int u,int p){
    fa[u] = p,sz[u] = 1,dpt[u] = dpt[p] + 1;
    for(auto v : adj[u]) if(v != p){
        dfs1(v,u);
        sz[u] += sz[v];
        if(sz[hsn[u]] < sz[v]) hsn[u] = v;
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
    int l = lca(u,v);
    dif[u] += k;
    dif[v] += k;
    dif[l] -= k;
    dif[fa[l]] -= k;
}

void dfs3(int u,int p){
    for(auto v : adj[u]) if(v != p){
        dfs3(v,u);
        dif[u] += dif[v];
    }
}


int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);

    cin >> n;
    for(int i = 1;i <= n;++i) cin >> a[i];
    for(int i = 0;i < n-1;++i){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y),adj[y].push_back(x);
    }

    dfs1(1,0);
    dfs2(1,1);

    for(int i = 1;i < n;++i){
        int x = a[i],y = a[i + 1];
        update(x,y,1);
        update(y,y,-1); // 由于最后一个房间不用吃 不如让这里少吃一个
    }
    dfs3(1,0);

    for(int i = 1;i <= n;++i)
        cout << dif[i] << "\n";
    return 0;
}
```
