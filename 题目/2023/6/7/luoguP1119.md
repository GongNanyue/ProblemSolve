[P1119 灾后重建](https://www.luogu.com.cn/problem/P1119)

> Floyd

Floyd的本质是动态规划 最外层的第k的循环是表示经过 0...k的子图 从x到y的最短距离

并且注意到这道题给出村庄重建的时间和询问的时间都是非严格递增的

```cpp
#include <bits/stdc++.h>

using namespace std;
const int N = 210;
int n, m;
int tim[N];//time to rebuild


struct qu {
    int x, y, t;

    bool operator<(const qu &other) const {
        return t < other.t;
    }
};

int dist[N][N];

int idx = 0;


void update() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][idx] + dist[idx][j]);
}

int main() {
    ::memset(dist, 0x3f, sizeof dist);


    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> tim[i];
    }
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        dist[x][y] = dist[y][x] = min(dist[x][y], w);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        while (tim[idx] <= t && idx < n) {
            update();
            idx++;
        }
        if (tim[x] > t || tim[y] > t)
            cout << -1 << "\n";
        else if (dist[x][y] > 0x3f3f3f3f / 2)
            cout << -1 << "\n";
        else
            cout << dist[x][y] << "\n";
    }

}
```
