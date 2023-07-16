[B - Strictly Superior](https://atcoder.jp/contests/abc310/tasks/abc310_b)

> 模拟

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;

struct good {
    int p;
    int c;
    vector<int> fs;

    good(int p, int c, const vector<int> &fs) {
        this->p = p;
        this->c = c;
        this->fs = fs;
        sort(this->fs.begin(), this->fs.end());
    }

    friend bool operator>(const good &jg, const good &ig) {
        return ig.p >= jg.p &&
               includes(jg.fs.begin(), jg.fs.end(), ig.fs.begin(), ig.fs.end()) &&
               (ig.p > jg.p || !includes(ig.fs.begin(), ig.fs.end(), jg.fs.begin(), jg.fs.end()));
    }
};

int main() {
    cin >> n >> m;
    vector<good> gs;
    for (int i = 0; i < n; ++i) {
        int p, c;
        cin >> p >> c;
        vector<int> fs(c);
        for (auto &v: fs) cin >> v;
        gs.push_back(good(p, c, fs));
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (gs[i] > gs[j]) {
                cout << "Yes\n";
                return 0;
            }
    cout << "No\n";
    return 0;
}
```
