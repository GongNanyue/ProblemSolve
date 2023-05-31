## P3374 【模板】树状数组 1
https://www.luogu.com.cn/problem/P3374

> [线段树](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%BA%BF%E6%AE%B5%E6%A0%91.md)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n, m;

struct node {
    int l, r;
    ll sum, add;

    node(int a = 0, int b = 0, ll c = 0, ll d = 0) : l(a), r(b), sum(c), add(d) {}
} tr[4 * N];

ll w[N];

int leftChild(int i) {
    return i * 2;
}

int rightChild(int i) {
    return i * 2 + 1;
}

void up(int p) {
    int lc = leftChild(p);
    int rc = rightChild(p);
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void down(int p) {
    if (tr[p].add != 0) {
        int lc = leftChild(p);
        int rc = rightChild(p);
        tr[lc].sum += tr[p].add * (tr[lc].r - tr[lc].l + 1);
        tr[rc].sum += tr[p].add * (tr[rc].r - tr[rc].l + 1);
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
        tr[p].add = 0;
    }
}

void build(int p, int l, int r) {
    tr[p] = {l, r, w[l], 0};
    if (l == r)return;
    int mid = (l + r) / 2;
    int lc = leftChild(p);
    int rc = rightChild(p);

    build(lc, l, mid);
    build(rc, mid + 1, r);
    up(p);

}

void update(int p, int x, int y, ll k) {
    if (x <= tr[p].l && tr[p].r <= y) {
        tr[p].add += k;
        tr[p].sum += k * (tr[p].r - tr[p].l + 1);
    } else {
        int mid = (tr[p].l + tr[p].r) / 2;
        int lc = leftChild(p);
        int rc = rightChild(p);
        down(p);
        if (x <= mid)
            update(lc, x, y, k);

        if (y >= mid + 1)
            update(rc, x, y, k);
        up(p);
    }
}


ll query(int p, int x, int y) {
    if (x <= tr[p].l && tr[p].r <= y)
        return tr[p].sum;
    else {
        int mid = (tr[p].l + tr[p].r) / 2;
        int lc = leftChild(p);
        int rc = rightChild(p);
        down(p);

        ll sum = 0;
        if (x <= mid)
            sum += query(lc, x, y);
        if (y >= mid + 1)
            sum += query(rc, x, y);
        return sum;
    }
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];

    build(1, 1, n);

    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            ll k;
            cin >> x >> k;
            update(1, x, x, k);
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            cout << query(1, x, y) << "\n";
        }
    }


    return 0;
}



```
