## 线段树模板题

> [线段树](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%BA%BF%E6%AE%B5%E6%A0%91.md)


P3372 【模板】线段树 1

https://www.luogu.com.cn/problem/P3372

不开long long见祖宗


```cpp
//https://www.luogu.com.cn/problem/P3372
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
const int N = 1e5 + 10;

int leftChild(int i) {
    return 2 * i;
}

int rightChild(int i) {
    return 2 * i + 1;
}

ll w[N]; //各个子节点的编号设为[1...n] 的原始数值

struct node {
    int l, r;
    ll sum, add;

    //左区间 右区间 总和 懒标记
    node(int a = 0, int b = 0, ll c = 0, ll d = 0)
            : l(a), r(b), sum(c), add(d) {}
} tree[4 * N]; //树根从1开始 四倍是为了有可能出现不是完美二叉树的情况

void up(int p) { // 把p的子树向上更新到p
    int lc = leftChild(p);
    int rc = rightChild(p);
    tree[p].sum = tree[lc].sum + tree[rc].sum;
}

void down(int p) { // 向下更新
    if (tree[p].add != 0) {//存在懒标记
        int lc = leftChild(p);
        int rc = rightChild(p);
        tree[lc].sum += tree[p].add * (tree[lc].r - tree[lc].l + 1); // 懒惰标记 * 左子树的宽度 l - r + 1
        tree[rc].sum += tree[p].add * (tree[rc].r - tree[rc].l + 1);
        tree[lc].add += tree[p].add;
        tree[rc].add += tree[p].add;
        tree[p].add = 0;
    }
}

void build(int p, int l, int r) {
    // int p -> parent
    tree[p] = {l, r, w[l], 0};
    if (l == r)return;
    int mid = (l + r) / 2;
    int lc = leftChild(p);
    int rc = rightChild(p);
    build(lc, l, mid);
    build(rc, mid + 1, r);
    up(p);
}

void update(int p, int x, int y, ll k) {
    // 修改[x,y]范围内的数值 把每一个树都加上k
    // 现在遍历到了以p为根的范围[tree[p].l,tree[p].r]
    if (x <= tree[p].l && tree[p].r <= y) {
        tree[p].sum += (tree[p].r - tree[p].l + 1) * k; // 加上 k * 宽度
        tree[p].add += k; //懒惰标记
    } else {//[x,y]不能完全覆盖[tree[p].l,tree[p].r], 分裂区间
        int mid = (tree[p].l + tree[p].r) / 2;
        int lc = leftChild(p);
        int rc = rightChild(p);
        down(p);
        if (x <= mid)
            update(lc, x, y, k);
        if (y > mid)
            update(rc, x, y, k);
        up(p);
    }
}

ll query(int p, int x, int y) {
    if (x <= tree[p].l && tree[p].r <= y) {
        return tree[p].sum;
    } else {
        int mid = (tree[p].l + tree[p].r) / 2;
        int lc = leftChild(p);
        int rc = rightChild(p);
        down(p);
        ll sum = 0;
        if (x <= mid)
            sum += query(lc, x, y);
        if (y > mid)
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
            int x, y;
            ll k;
            cin >> x >> y >> k;
            update(1, x, y, k);
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            cout << query(1, x, y) << "\n";
        }
    }

    return 0;
}
```
