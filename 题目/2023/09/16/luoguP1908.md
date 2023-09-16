[P1908 逆序对](https://www.luogu.com.cn/problem/P1908)

> 归并排序

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
long long n, ans;
int a[N];
void mergeSort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid), mergeSort(mid + 1, r);
    vector<int> t;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            t.push_back(a[i]);
            ++i;
        } else {
            t.push_back(a[j]);
            ++j;
            ans += mid - i + 1;
        }
    }
    while (i <= mid) {
        t.push_back(a[i]);
        ++i;
    }

    while (j <= r) {
        t.push_back(a[j]);
        ++j;
    }


    for (int k = l; k <= r; ++k) a[k] = t[k - l];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    mergeSort(1, n);
    cout << ans << '\n';

    return 0;
}
```
