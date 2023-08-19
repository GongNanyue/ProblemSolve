[E - Prerequisites](https://atcoder.jp/contests/abc315/tasks/abc315_e)



在1号点可以到达的范围内进行拓扑排序
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> inedge;
vector<vector<int>> adj;
vector<vector<int>> rdj;
vector<bool> comp;
vector<int> path;
int n;

void dfs() {
    stack<int, vector<int>> st;
    st.push(1);

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        comp[u] = true;
        for (auto v: rdj[u]) {
            if (!comp[v]) {
                st.push(v);
            }
        }
    }
}


void topology() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (inedge[i] == 0 && comp[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        path.push_back(u);
        if (u == 1) return;
        for (auto v: adj[u]) {
            if (comp[v]) {
                inedge[v]--;
                if (inedge[v] == 0) {
                    q.push(v);
                }
            }
        }
    }


}

int main() {
    cin >> n;
    inedge.resize(n + 1);
    adj.resize(n + 1);
    comp.resize(n + 1);
    rdj.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> inedge[i];
        for (int j = 0; j < inedge[i]; ++j) {
            int p;
            cin >> p;
            adj[p].push_back(i);
            rdj[i].push_back(p);
        }
    }
    dfs();
    topology();
    for (int i = 0; i < path.size() - 1; ++i)
        cout << path[i] << " ";

    return 0;
}
```
