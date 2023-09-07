[P5018 [NOIP2018 普及组] 对称二叉树](https://www.luogu.com.cn/problem/P5018)


> 字符串哈希

```cpp
#include <bits/stdc++.h>
using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;

struct HashStr {
    u32 base1 = 131, base2 = 13331, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    vector<u32> H1, H2, P1, P2;

    HashStr(const string &s) {
        H1.resize(s.size() + 1), H2.resize(s.size() + 1);
        P1.resize(s.size() + 1), P2.resize(s.size() + 1);
        P1[0] = P2[0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            P1[i] = (1ull * P1[i - 1] * base1) % mod1;
            P2[i] = (1ull * P2[i - 1] * base2) % mod2;
            // 将string的下标后移一位
            H1[i] = (1ull * H1[i - 1] * base1 + s[i - 1]) % mod1;
            H2[i] = (1ull * H2[i - 1] * base2 + s[i - 1]) % mod2;
        }
    }

    pair<u32, u32> get(int l, int r) { // l,r 下标从1开始
        u32 h1 = (H1[r] - 1ull * H1[l - 1] * P1[r - (l - 1)] % mod1 + mod1) % mod1;
        u32 h2 = (H2[r] - 1ull * H2[l - 1] * P2[r - (l - 1)] % mod2 + mod2) % mod2;
        return {h1, h2};
    }

};

const int N = 1e6 + 10;
int n;
struct node {
    int lc, rc, w, sz{0};
    int l1, r1, l2, r2;

} adj[N];

void dfs1(int u, int p, string &s) {
    if (u == -1)
        s += "x";
    else {
        adj[u].sz = 1;
        s += to_string(adj[u].w);
        adj[u].l1 = s.size();

        dfs1(adj[u].lc, u, s);
        adj[u].sz += adj[adj[u].lc].sz;

        dfs1(adj[u].rc, u, s);
        adj[u].sz += adj[adj[u].rc].sz;

        adj[u].r1 = s.size();
    }
}

void dfs2(int u, int p, string &s) {
    // 按照 根 左 右 来进行dfs形成权重序列
    if (u == -1)
        s += "x";
    else {
        s += to_string(adj[u].w);
        adj[u].l2 = s.size();

        dfs2(adj[u].rc, u, s);
        dfs2(adj[u].lc, u, s);

        adj[u].r2 = s.size();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> adj[i].w;
    for (int i = 1; i <= n; ++i) cin >> adj[i].lc >> adj[i].rc;
    string s1, s2;
    dfs1(1, 1, s1);
    dfs2(1, 1, s2);
    HashStr h1(s1), h2(s2);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int sz = adj[i].sz;
        int l1 = adj[i].l1, l2 = adj[i].l2;
        int r1 = adj[i].r1, r2 = adj[i].r2;
        if (h1.get(l1, r1) == h2.get(l2, r2))
            ans = max(ans, sz);
    }
    cout << ans << "\n";
    return 0;
}

```
