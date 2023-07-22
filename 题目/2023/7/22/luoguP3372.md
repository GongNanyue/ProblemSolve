[P3372 【模板】线段树 1](https://www.luogu.com.cn/problem/P3372)

> [线段树](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%BA%BF%E6%AE%B5%E6%A0%91.md)

```cpp
#include <bits/stdc++.h>

const int N = 1e5 + 10;
int n, m;
using ll = long long;
int a[N];
ll tr[4 * N], tag[4 * N];

auto ls = [](int x) { return 2 * x; };
auto rs = [](int x) { return 2 * x + 1; };

void push_up(int p) {
    tr[p] = tr[ls(p)] + tr[rs(p)];
}

void add_interval(int p, int l, int r, int k) {
    // 在p管辖[l,r]中每个数加上x
    tr[p] += (ll)1 * (r - l + 1) * k;
    tag[p] += k;
}

void push_down(int p, int l, int r) {
    if (tag[p] == 0) return;
    int mid = (l + r) / 2;
    add_interval(ls(p), l, mid, tag[p]), add_interval(rs(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}


void build(int p, int l, int r) {
    if (l == r) {
        tr[p] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(ls(p), l, mid), build(rs(p), mid + 1, r);
        push_up(p);
    }
}

ll ask_interval(int p, int l, int r, int L, int R) {// p节点管辖[l,r]
    //查询[L,R]区域内和
    if (r < L || l > R) return 0;
    if (L <= l && r <= R) return tr[p];
    int mid = (l + r) / 2;
    push_down(p, l, r);
    return ask_interval(ls(p), l, mid, L, R) + ask_interval(rs(p), mid + 1, r, L, R);
}

void add_point(int p, int l, int r, int x, int k) {// p节点管辖[l,r]
    // 在x位置上加上k
    if (l == r) tr[l] += k;
    int mid = (l + r) / 2;
    if (x <= mid) add_point(ls(p), l, mid, x, k);
    else add_point(rs(p), mid + 1, r, x, k);
    push_up(p);
}


void add_interval(int p, int l, int r, int L, int R, int k) {
    // p管辖区间[l,r] 在区间[L,R]中每个数加上k
    if (r < L || l > R) return;
    if (L <= l && r <= R) return add_interval(p, l, r, k);
    int mid = (l + r) / 2;
    push_down(p, l, r);
    add_interval(ls(p), l, mid, L, R, k), add_interval(rs(p), mid + 1, r, L, R, k);
    push_up(p);
}


int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];

    build(1, 1, n);

    int op, x, y, k;
    while (m--) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y >> k;
            add_interval(1, 1, n, x, y, k);


        } else if (op == 2) {
            std::cin >> x >> y;
            std::cout << ask_interval(1, 1, n, x, y) << "\n";
        }
    }


    return 0;
}
```
