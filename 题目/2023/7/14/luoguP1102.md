[P1102 A-B 数对](https://www.luogu.com.cn/problem/P1102)

> 双指针

```cpp
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int n, c;
int main() {
	cin >> n >> c;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)cin >> a[i];
    sort(a.begin(),a.end());
    
	int l = 0, r1 = 0, r2 = 0;
	ull ans = 0;
	for (; l < n ;++l) {
		while (r1 < n && a[r1] - a[l] < c) ++ r1;
		while (r2 < n && a[r2] - a[l] <= c) ++ r2;
		if (a[r1] - a[l] == c && a[r2 - 1] - a[l] == c)
			ans += r2 - r1;
	}
	cout << ans << "\n";
}
```
