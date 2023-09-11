[P1495 【模板】中国剩余定理（CRT）/ 曹冲养猪](https://www.luogu.com.cn/problem/P1495)

> 中国剩余定理

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;


ll exgcd(ll a,ll b,ll &x,ll &y){
    if(a % b == 0){
        x = 0,y = 1;
        return b;
    }else{
        ll d = exgcd(b,a % b,y,x);
        y -= a / b * x;
        return d;
    }
}

ll inv(ll a,ll m){
    ll x,y;
    exgcd(a,m,x,y);
    return (x % m + m) % m;
}


ll CRT(vector<ll> M,vector<ll> R){
    // M 模数
    // R 余数
    // 求解对于所有的 x % M[i] = R[i] 的x
    // 中国剩余定理
    
    ll Mm = 1; // 所有模数M的乘积
    for(int i = 0;i < M.size();++i) Mm *= M[i];
    vector<ll> N(M.size()); // N[i] = Mm / M[i]
    vector<ll> Nr(M.size()); 
    vector<ll> res(M.size()); // res[i] = N[i] * Nr[i] * R[i]
    // Nr[i] = N[i]^-1 % M[i] 
    // Nr 是N在M[i]的逆元
    for(int i = 0;i < M.size();++i) {
        N[i] = Mm / M[i];
        Nr[i] = inv(N[i],M[i]);
        res[i] = N[i] * Nr[i] * R[i];
    }
    ll ans = 0;
    for(int i = 0;i < M.size();++i) ans += res[i];
    return ans % Mm;
}


int main(){
    int N;
    cin >> N;
    vector<ll> m,r;
    m.resize(N),r.resize(N);
    for(int i = 0;i < N;++i) {
        cin >> m[i] >> r[i];
    }
    cout << CRT(m,r) << endl;
    return 0;
}
```
