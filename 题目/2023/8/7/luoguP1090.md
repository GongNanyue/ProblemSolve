[P1090 [NOIP2004 提高组] 合并果子 / [USACO06NOV] Fence Repair G](https://www.luogu.com.cn/problem/P1090)


> 堆
> 贪心


```cpp
#include <bits/stdc++.h>
const int N = 1e4 + 10;
int heap[N], sz;//小根堆
int n;


void push_up(int u) {
    if (u > 1 && heap[u] < heap[u / 2]) {
        std::swap(heap[u], heap[u / 2]);
        push_up(u / 2);
    }
}

void push_down(int u) {
    int maxU = u;
    if (2 * u <= sz && heap[maxU] > heap[2 * u]) {
        maxU = 2 * u;
    }
    if (2 * u + 1 <= sz && heap[maxU] > heap[2 * u + 1]) {
        maxU = 2 * u + 1;
    }
    if (maxU != u) {
        std::swap(heap[maxU], heap[u]);
        push_down(maxU);
    }
}

int top() {
    return heap[1];
}

void pop() {
    std::swap(heap[1], heap[sz]);
    sz--;
    push_down(1);
}

void insert(int val) {
    heap[++sz] = val;
    push_up(sz);
}

int size() {
    return sz;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int val;
        std::cin >> val;
        insert(val);
    }
    int cost = 0;
    while (size() > 1){
        int a = top();pop();
        int b = top();pop();
        cost += a + b;
        insert(a + b);
    }

    std::cout << cost << "\n";
    return 0;
}


```
