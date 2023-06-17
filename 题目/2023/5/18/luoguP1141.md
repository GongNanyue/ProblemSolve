[P1141 01迷宫](https://www.luogu.com.cn/problem/P1141)

```cpp

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int n, m;
vector<vector<bool>> M;
vector<vector<pair<int,int>>> parent;
vector<vector<int>> res;
vector<vector<bool>> vis;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};



pair<int, int> findAncestor(pair<int, int> p) {
    return parent[p.first][p.second] == p ? p : parent[p.first][p.second] = findAncestor(parent[p.first][p.second]);
}

bool inBound(int a, int b) {
    return 1 <= a && a <= n && 1 <= b && b <= n;
}


void bfs(int a, int b) {

    queue<pair<int, int>> q;
    vis[a][b] = true;
    q.emplace(a, b);
    while (!q.empty()) {
        a = q.front().first;
        b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            auto x = a + dx[i];
            auto y = b + dy[i];
            if (inBound(x, y) && ( M[a][b] != M[x][y] ) && !vis[x][y]) {
                vis[x][y] = true;
                q.emplace(x, y);
                parent[x][y] = findAncestor({a, b});
                auto anc = findAncestor({a,b});
                res[anc.first][anc.second]++;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    M.resize(n + 1, vector<bool>(n + 1));
    vis.resize(n + 1, vector<bool>(n + 1));
    parent.resize(n+1,vector<pair<int,int>>(n+1));
    res.resize(n+1,vector<int>(n+1));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            parent[i][j] = {i, j};
            res[i][j] = 1;
            char c;
            cin >> c;
            M[i][j] = (c == '1');
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (!vis[i][j])
                bfs(i, j);
        }


    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        auto anc = findAncestor({x,y});
        cout << res[anc.first][anc.second] << "\n";
    }


    return 0;
}
```
