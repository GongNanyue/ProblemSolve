[P8436 【模板】边双连通分量](https://www.luogu.com.cn/problem/P8436)


```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10, M = 2e6+10;
int n,m;
int hd[N],e[M],ne[M],idx = 1;
void addEdge(int u,int v){
    e[++idx] = v,ne[idx] = hd[u],hd[u] = idx;
}
int dfn[N],low[N],ts;
bool brg[N];
void dfs(int u,int ine){
    dfn[u] = low[u] = ++ ts;
    for(int i = hd[u];i != 0;i = ne[i]){
        if(i == ine) continue;
        int v = e[i];
        if(dfn[v] == 0){
            dfs(v,i ^ 1);
            low[u] = min(low[u],low[v]);
            if(low[v] > dfn[u]) 
                brg[i] = brg[i ^ 1] = true;
        }else low[u] = min(low[u],dfn[v]);
    }
}
bool vis[N];
vector<int> bcc[N];// binary connected component 双连通分量
int cc;// component count
void dfs2(int u){
    bcc[cc].push_back(u);
    vis[u] = true;
    for(int i = hd[u];i != 0;i = ne[i]){
        if(brg[i]) continue;
        int v = e[i];
        if(!vis[v]) dfs2(v);
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0;i < m;++i){
        int x,y;
        cin >> x >> y;
        addEdge(x,y), addEdge(y,x);
    }
    for(int i = 1;i <= n;++i)
        if(dfn[i] == 0)
            dfs(i,0);


    for(int i = 1;i <= n;++i)
        if(!vis[i]){
            ++cc;
            dfs2(i);
        }
    cout << cc << "\n";
    for(int i = 1;i <= cc;++i){
        cout << bcc[i].size() << " ";
        for(auto v : bcc[i])
            cout << v << " ";
        cout << "\n";
    }        
    return 0;
}
```
