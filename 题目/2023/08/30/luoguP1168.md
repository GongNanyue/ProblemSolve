[P1168 中位数](https://www.luogu.com.cn/problem/P1168)

> 堆/对顶堆


```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    priority_queue<int> q1;

    priority_queue<int, vector<int>, greater<>> q2;
    for (int k = 0; k < n; ++k) {
        cin >> x;
        if (q1.empty() || x <= q1.top()) q1.push(x);
        else q2.push(x);
        if (q1.size() > q2.size() + 1) q2.push(q1.top()), q1.pop();
        if (q1.size() < q2.size()) q1.push(q2.top()), q2.pop();
        if (k % 2 == 0) cout << q1.top() << "\n";
    }

    return 0;
}
```
