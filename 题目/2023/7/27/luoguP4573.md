[P4573 [CQOI2013] 新数独](https://www.luogu.com.cn/problem/P4573)

> [dfs](https://github.com/GongNanyue/ProblemSolve/blob/main/搜索/广度优先搜索.md)

```cpp
#include <bits/stdc++.h>

int D[] = {2, 3, 2, 3, 2};
std::string rls[9][9];//relations
std::vector<std::vector<int>> Ps[3][3];//单个九宫格满足关系的排列
int ans[9][9];//九宫格的答案
bool Xoc[9][10];// X occur
bool Yoc[9][10];// Y occur


void dfs(int i, int j) {
//i,j都表示九宫格的坐标

    if (i == 3) {
        for (int x = 0; x < 9; ++x)
            for (int y = 0; y < 9; ++y)
                std::cout << ans[x][y] << " \n"[y == 8];
        exit(0);//使用exit(0)直接结束所有程序
    } else {


        for (const auto &pm: Ps[i][j]) {
            int N[3][3], t = 0;
            for (int x = 0; x < 3; ++x)
                for (int y = 0; y < 3; ++y)
                    N[x][y] = pm[t++];

            bool flag = true;
            for (int x = 0; x < 3; ++x)
                for (int y = 0; y < 3; ++y) {
                    int a = 3 * i + x, b = 3 * j + y;
                    flag &= !Xoc[a][N[x][y]];//如果在x轴上这个数字没有被用过
                    flag &= !Yoc[b][N[x][y]];//如果在y轴上这个数字没有被用过
                }

            if (flag) {
                //更改
                for (int x = 0; x < 3; ++x)
                    for (int y = 0; y < 3; ++y) {
                        int a = 3 * i + x, b = 3 * j + y;
                        Xoc[a][N[x][y]] = true;
                        Yoc[b][N[x][y]] = true;
                        ans[a][b] = N[x][y];
                    }

                if (j == 2)//换下一行行
                    dfs(i + 1, 0);
                else
                    dfs(i, j + 1);

                //恢复
                for (int x = 0; x < 3; ++x)
                    for (int y = 0; y < 3; ++y) {
                        int a = 3 * i + x, b = 3 * j + y;
                        Xoc[a][N[x][y]] = false;
                        Yoc[b][N[x][y]] = false;
                        ans[a][b] = 0;
                    }
            }
        }
    }
}


int main() {
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);


    for (int i = 0; i < 3; ++i)
        for (int x = 0; x < 5; ++x)
            for (int j = 0; j < 3; ++j)
                for (int y = 0; y < D[x]; ++y) {
                    char c;
                    std::cin >> c;
                    rls[i][j].push_back(c);
                }
    
    // 尝试找出符合单个九宫格的所有组合
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            std::vector<int> pm = {1, 2, 3, 4, 5, 6, 7, 8, 9};//permutaion array

            do {
                int flag = true;

                flag &= pm[0] < pm[1] ? rls[i][j][0] == '<' : rls[i][j][0] == '>';
                flag &= pm[1] < pm[2] ? rls[i][j][1] == '<' : rls[i][j][1] == '>';
                flag &= pm[3] < pm[4] ? rls[i][j][5] == '<' : rls[i][j][5] == '>';
                flag &= pm[4] < pm[5] ? rls[i][j][6] == '<' : rls[i][j][6] == '>';
                flag &= pm[6] < pm[7] ? rls[i][j][10] == '<' : rls[i][j][10] == '>';
                flag &= pm[7] < pm[8] ? rls[i][j][11] == '<' : rls[i][j][11] == '>';


                flag &= pm[0] < pm[3] ? rls[i][j][2] == '^' : rls[i][j][2] == 'v';
                flag &= pm[1] < pm[4] ? rls[i][j][3] == '^' : rls[i][j][3] == 'v';
                flag &= pm[2] < pm[5] ? rls[i][j][4] == '^' : rls[i][j][4] == 'v';
                flag &= pm[3] < pm[6] ? rls[i][j][7] == '^' : rls[i][j][7] == 'v';
                flag &= pm[4] < pm[7] ? rls[i][j][8] == '^' : rls[i][j][8] == 'v';
                flag &= pm[5] < pm[8] ? rls[i][j][9] == '^' : rls[i][j][9] == 'v';

                if (flag) {
                    Ps[i][j].push_back(pm);
                    //每个九宫格可能有多个组合满足
                }
            } while (std::next_permutation(pm.begin(), pm.end()));


        }
    dfs(0, 0);

    return 0;
}
```
