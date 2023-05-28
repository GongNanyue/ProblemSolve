P1219 [USACO1.5]八皇后 Checker Challenge

https://www.luogu.com.cn/problem/P1219



深度优先搜索 层数从1开始

a表示的是每行中的皇后的位置

b表示每列中是否有皇后 有是1 没有是0

c表示从左下到右上对角线是否有皇后 

使用向下y轴 向右x轴

范围是[1,2n] y = -x + k => k = x + y

d表示从左上到右下对角线是否有皇后

范围是[-n+1,n] 所以加上n作为偏移量保证数组不越界

y = x + k => k = y - x ----> k =y -x + n

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[100], b[100], c[100], d[100];

int n, cnt;

void print() {
    ++cnt;
    if (cnt <= 3)
        for (int i = 1; i <= n; ++i)
            cout << a[i] << " \n"[i == n];
}

void dfs(int layer) {
    if (layer > n)
        print();
    else {
        for (int i = 1; i <= n; ++i) {
            if (!b[i] && !c[layer + i] && !d[layer - i + n]) {
                a[layer] = i;
                b[i] = 1;
                c[layer + i] = 1;
                d[layer - i + n] = 1;

                dfs(layer + 1);

                d[layer - i + n] = 0;
                c[layer + i] = 0;
                b[i] = 0;
                a[layer] = 0;
            }
        }


    }
}

int main() {

    cin >> n;
    dfs(1);
    cout << cnt << "\n";

    return 0;
}
```

