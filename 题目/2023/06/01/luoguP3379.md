[P3379 【模板】最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379)

> [树链剖分](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%A0%91%E4%B8%8A%E9%97%AE%E9%A2%98/%E6%A0%91%E9%93%BE%E5%89%96%E5%88%86.md)
> [最近公共祖先](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%9B%BE%E8%AE%BA/%E6%A0%91%E4%B8%8A%E9%97%AE%E9%A2%98/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.md)


```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 10;
int n,m,s;
vector<int> adj[N];
int sz[N],fa[N],hsn[N],dpt[N],top[N];
// sz 子树大小 
// fa 父亲节点
// hsn 重儿子
// dpt 深度
// top 重链的头结点
void dfs1(int u,int p){
    sz[u] = 1;
    fa[u] = p;
    dpt[u] = dpt[p] + 1;
    for(auto v : adj[u]) if(v != p){
        dfs1(v,u);
        sz[u] += sz[v];
        if(sz[v] > sz[hsn[u]]) hsn[u] = v;
    }
}

void dfs2(int u,int tp){
    // tp u的这条重链上的头结点
    top[u] = tp;
    if(hsn[u] == 0) return; // 叶子结点没有重儿子
    dfs2(hsn[u],tp); // 先处理重链上所有节点

    for(auto v : adj[u]) if(v != fa[u] && v != hsn[u])
        dfs2(v,v);// 重新开辟新的重链
}

int lca(int u,int v){
    // 深度更深的往上跳
    while(top[u] != top[v]){
        if(dpt[top[u]] > dpt[top[v]]) u = fa[top[u]]; // 头结点深度深的跳到头结点的父亲节点
        else v = fa[top[v]];
    }
    return dpt[u] < dpt[v] ? u : v; // 深度浅的是lca
}
int main(){
    cin >> n >> m >> s;
    for(int i = 0;i < n - 1;++i){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs1(s,s);
    dfs2(s,s);

    while(m--){
        int u,v;
        cin >> u >> v;
        cout << lca(u,v) << "\n";
    }
    return 0;
}
```
