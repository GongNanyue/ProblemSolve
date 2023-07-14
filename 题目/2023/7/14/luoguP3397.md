[P3397 地毯](https://www.luogu.com.cn/problem/P3397)

> [差分](https://github.com/GongNanyue/ProblemSolve/blob/main/%E7%AE%97%E6%B3%95%E5%9F%BA%E7%A1%80/%E5%89%8D%E7%BC%80%E5%92%8C%E5%B7%AE%E5%88%86.md)

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr);
	cin >> n >> m;
	vector<vector<int>> d(n + 1, vector<int>(n + 1)), a(n + 1, vector<int>(n + 1));

	while (m--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		d[x1][y1]++;
		if (y2 + 1 <= n)d[x1][y2 + 1]--;
		if (x2 + 1 <= n)d[x2 + 1][y1]--;
		if (x2 + 1 <= n && y2 + 1 <= n) d[x2 + 1][y2 + 1]++; }

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + d[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cout << a[i][j] << " \n"[j == n];
	return 0; }
```
