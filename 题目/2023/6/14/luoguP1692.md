[P1692 部落卫队](https://www.luogu.com.cn/problem/P1692)

 ```cpp
 #include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;

const int N = 110;
bool M[N][N];
int n, m;

int cnt;
std::unordered_set<int> sec;
std::unordered_set<int> res;

void dfs(int layer) {
    bool out = true;

    for (int i = layer; i <= n; ++i) {
        if (sec.count(i) == 0) {
            if (sec.empty()) {
                out = false;
                sec.insert(i);
                dfs(i + 1);
                sec.erase(i);
            } else {
                bool flag = true;
                for (auto val: sec) {
                    if (M[val][i]) {
                        flag = false;
                    }
                }

                if (flag){
                    out = false;
                    sec.insert(i);
                    dfs(i + 1);
                    sec.erase(i );
                }


            }


        }
    }

    if (out) {
        if (sec.size() > cnt) {
            cnt = sec.size();
            res = sec;
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        M[x][y] = M[y][x] = true;
    }

    dfs(1);
    cout << cnt << "\n";
    for (int i = 1; i <= n; ++i)
        if (res.count(i) == 1)
            cout << 1 << " ";
        else
            cout << 0 << " ";

    return 0;
}
 
 ```
