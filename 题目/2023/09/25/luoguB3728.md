[B3728 扔骰子问题 2](https://www.luogu.com.cn/problem/B3728)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3+10,M = 6e3+10,md = 998244353;
int f[N][M];
int pw6[N];
int inv[N];// the inverse of pow(6,n)

constexpr int getInv(int x){
	return x == 1 ? 1 : md - 1LL * md / x * getInv(md % x) % md;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	f[0][0] = 1;
	for(int i = 1;i <= N - 1;++i)
		for(int j = 1;j <= M - 1;++j)
			for(int k = 1;k <= 6;++k)
				if(j - k >= 0)
					f[i][j] =(f[i][j] + f[i-1][j - k]) % md;
	inv[0] = 1;
	for(int i = 1;i <= N - 1;++i)
		inv[i] = 1LL * inv[i-1] * getInv(6) % md;
		
	int t,ans = 0;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		ans =  ans ^ (1LL * f[n][m] * inv[n] % md);
	}
	cout << ans << "\n";
	
	return 0;
}
```
