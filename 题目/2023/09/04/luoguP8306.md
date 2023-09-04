[P8306 【模板】字典树](https://www.luogu.com.cn/problem/P8306)

> 字典树


```cpp
#include <bits/stdc++.h>
using namespace std;


struct Tire {
    struct node {
        map<char, int> mp;
        int wdc{};
        // 计算这个节点为根节点的子树中插入的单词的的个数
        // 相同的单词插入也增加数量
    };
    vector<node> tr;

    Tire() { tr.assign(1, node()); }

    void insert(const string &s) {
        int p = 0;
        tr[p].wdc++;// 所有插入单词的数量
        for (auto c: s) {

            if (tr[p].mp.count(c) == 0) {
                tr.push_back(node());
                tr[p].mp[c] = tr.size() - 1;
            }
            p = tr[p].mp[c];
            tr[p].wdc++;
            // 保证单词的最后也能加上
        }
    }

    int query(const string &s) {
        int p = 0;
        for (auto c: s) {
            if (tr[p].mp.count(c) == 0) return 0;
            p = tr[p].mp[c];
        }
        return tr[p].wdc;
    }
};

void solve() {
    int n, q;
    string s;
    Tire tr;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        tr.insert(s);
    }
    for (int i = 0; i < q; ++i) {
        cin >> s;
        cout << tr.query(s) << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```
