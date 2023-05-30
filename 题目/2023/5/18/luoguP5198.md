https://www.luogu.com.cn/problem/P5198


```cpp
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int n;

bool inBound(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

vector<vector<char>> M;

vector<vector<vector<pair<int, int>>>> comp;

vector<vector<pair<int, int>>> ancestor;

pair<int, int> findAncestor(pair<int, int> p) {
    if (ancestor[p.first][p.second] == p)
        return p;
    else {
        return ancestor[p.first][p.second] =
                       findAncestor(ancestor[p.first][p.second]);
    }
}

vector<vector<bool>> vis;

void bfs(int a, int b) {

    queue<pair<int, int>> q;
    vis[a][b] = true;
    comp[a][b].push_back({a, b});
    q.push({a, b});
    while (!q.empty()) {
        a = q.front().first;
        b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = a + dx[i];
            int y = b + dy[i];
            if (inBound(x, y) && M[x][y] == '#'  &&!vis[x][y]) {
                vis[x][y] = true;
                q.push({x, y});
                auto root = findAncestor({a, b});
                ancestor[x][y] = root;
                comp[root.first][root.second].push_back({x, y});
            }
        }
    }
}

int area = 0, cir = 0x3f3f3f3f;

void cal() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (vis[i][j] && ancestor[i][j] == pair<int, int>(i, j)) {
                int a = 0, c = 0;
                for (const auto &item: comp[i][j]) {
                    a++;
                    for (int k = 0; k < 4; ++k) {
                        int x = item.first + dx[k];
                        int y = item.second + dy[k];
                        if (0 <= x && x <= n+1 && 0 <= y && y <= n+1 && M[x][y] == '.')
                            c++;
                    }
                }

                if (a >= area) {
                    area = a;
                    cir = c;
                    if (c < cir)
                        cir = c;
                }
            }
}

int main() {
    cin >> n;
    M.resize(n + 2, vector<char>(n + 2,'.'));
    ancestor.resize(n + 2, vector<pair<int, int>>(n + 2));
    vis.resize(n + 2, vector<bool>(n + 2));
    comp.resize(n + 2, vector<vector<pair<int, int>>>(n + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) { cin >> M[i][j];
        ancestor[i][j] = pair<int,int>(i,j);}
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if ( M[i][j] == '#' &&  !vis[i][j])
                bfs(i, j);

    cal();
    cout << area << " " << cir << "\n";

    return 0;
}
```
