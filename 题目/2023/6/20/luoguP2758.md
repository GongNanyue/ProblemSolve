https://www.luogu.com.cn/problem/P2758

> [线性dp](https://github.com/GongNanyue/ProblemSolve/blob/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/%E7%BA%BF%E6%80%A7dp.md)

```cpp
#include <bits/stdc++.h>
const int N =2020;
char a[N],b[N];
int dp[N][N];
int n,m;
int main() {
	std::string p,q;
	std::cin >> p >> q;
	for(int i = 0;i < p.size();++i)
		a[i+1] = p[i];
	for(int i = 0;i < q.size();++i)
		b[i+1] = q[i];
	n = p.size();
	m = q.size();
	
	for(int i = 1;i <= n;++i)
		dp[i][0] = i;
	for(int i = 1;i <= m;++i)
		dp[0][i] = i;
	
	
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;++j){
			if(a[i] == b[j])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = std::min({dp[i-1][j-1] + 1, dp[i][j-1] + 1, dp[i-1][j] + 1});
		}
	
	printf("%d\n",dp[n][m]);
	
	return 0;
}

```
