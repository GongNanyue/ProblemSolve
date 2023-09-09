[P5836 [USACO19DEC] Milk Visits S](https://www.luogu.com.cn/problem/P5836)

> lca

树上前缀和 H[u] 表示1->u的这一条链上的H个数
然后查询差分 u -> v == u -> lca(u,v) -> v 
那么链上的数量是 H[u] + H[v] - H[lca] - H[father[lca]]

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,m;
vector<int> adj[N];
char ct[N];// category

int fa[N],sz[N],dpt[N],hsn[N],top[N];
int H[N],G[N];


void dfs1(int u,int p){
    fa[u] = p,sz[u] = 1,dpt[u] = dpt[p] + 1;
    
    if(ct[u] == 'H') H[u] ++;
    else if(ct[u] == 'G') G[u] ++;
    H[u] += H[p],G[u] += G[p];


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
    while(top[u]!= top[v]){
        if(dpt[top[u]] < dpt[top[v]]) swap(u,v);
        u = fa[top[u]];
    }
    return dpt[u] < dpt[v] ? u : v;
}




int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> ct[i];
    for(int i = 0;i < n - 1;++i){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y), adj[y].push_back(x);
    }
    dfs1(1,0),dfs2(1,0);


    while(m--){
        int a,b;
        char c;
        cin >> a >> b >> c;
        int l = lca(a,b);
        if(c == 'H'){
            if((H[a] + H[b] - H[l] - H[fa[l]]) == 0) 
                cout << 0;
            else cout << 1;

        }else if(c == 'G'){
            if((G[a] + G[b] - G[l] - G[fa[l]]) == 0) 
                cout << 0;
            else cout << 1;
        }
        
    }   

    return 0;
}

```
