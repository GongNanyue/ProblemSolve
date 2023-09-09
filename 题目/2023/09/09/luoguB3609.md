[B3609 [图论与代数结构 701] 强连通分量](https://www.luogu.com.cn/problem/B3609)

> 强联通分量 Tarjan

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int V; // 顶点数
    vector<vector<int>> adj; // 邻接表
    vector<bool> visited; // 用于跟踪顶点是否已经被访问
    vector<int> timestamp; // 记录每个顶点的时间戳
    vector<int> low; // 记录每个顶点的low值
    stack<int> st; // 用于DFS的栈
    int currTimestamp; // 当前时间戳

    void DFS(int u, vector<vector<int>>& SCCs);

public:
    Graph(int vertices);
    void addEdge(int u, int v);
    vector<vector<int>> findSCCs();
};

Graph::Graph(int vertices) {
    V = vertices;
    adj.resize(V);
    visited.assign(V, false);
    timestamp.assign(V, -1);
    low.assign(V, -1);
    currTimestamp = 0;
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::DFS(int u, vector<vector<int>>& SCCs) {
    timestamp[u] = low[u] = currTimestamp++;
    st.push(u);
    visited[u] = true;

    for (int v : adj[u]) {
        if (timestamp[v] == -1) {
            // 如果v未被访问，递归访问v
            DFS(v, SCCs);
            low[u] = min(low[u], low[v]);
        } else if (visited[v]) {
            // 如果v已被访问，且在栈中，更新u的low值
            low[u] = min(low[u], timestamp[v]);
        }
    }

    // 如果u是强联通分量的根节点
    if (timestamp[u] == low[u]) {
        vector<int> SCC;
        int v;
        do {
            v = st.top();
            st.pop();
            visited[v] = false;
            SCC.push_back(v);
        } while (v != u);
        SCCs.push_back(SCC);
    }
}

vector<vector<int>> Graph::findSCCs() {
    vector<vector<int>> SCCs;
    for (int i = 0; i < V; ++i) {
        if (timestamp[i] == -1) {
            // 如果顶点i未被访问，以i为起点开始DFS
            DFS(i, SCCs);
        }
    }
    return SCCs;
}

int main() {
    int n,m;
    cin >> n >> m;
    Graph graph(n);
    for(int i = 0;i < m;++i){
        int x,y;
        cin >> x >> y;
        x--,y--;
        graph.addEdge(x,y);
    }

   
    vector<vector<int>> SCCs = graph.findSCCs();

    cout << SCCs.size() << "\n";

    vector<int> bein(n);
    for(int i = 0;i < SCCs.size();++i)
        for(auto v : SCCs[i])
            bein[v] = i;
    
    unordered_set<int> s;

    for(int i = 0;i < n;++i){
        if(s.count(i) == 1) continue;
        auto &scc = SCCs[bein[i]];
        sort(scc.begin(),scc.end());

        for(auto v : scc){
            cout << v + 1<< " ";
            s.insert(v);    
        }
        cout << "\n";
    }
    return 0;
}
```
