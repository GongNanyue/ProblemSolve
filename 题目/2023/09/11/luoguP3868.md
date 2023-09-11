[P3868 [TJOI2009] 猜数字](https://www.luogu.com.cn/problem/P3868)https://www.luogu.com.cn/problem/P3868

> 中国剩余定理

注意要开int128 不然最后一个会WA

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using i128 = __int128;

i128 exgcd(i128 a,i128 b,i128 &x,i128 &y){
    if(a % b == 0){
        x = 0,y = 1;
        return b;
    }else{
        ll d = exgcd(b,a % b,y,x);
        y -= a / b * x;
        return d;
    }
}

i128 inv(i128 a,i128 m){
    i128 x,y;
    exgcd(a,m,x,y);
    return (x % m + m) % m;
}


i128 CRT(vector<i128> M,vector<i128> R){
    // M 模数
    // R 余数
    // 求解对于所有的 x % M[i] = R[i] 的x
    // 中国剩余定理
    
    i128 Mm = 1; // 所有模数M的乘积
    for(int i = 0;i < M.size();++i) Mm *= M[i];
    vector<i128> N(M.size()); // N[i] = Mm / M[i]
    vector<i128> Nr(M.size()); 
    vector<i128> res(M.size()); // res[i] = N[i] * Nr[i] * R[i]
    // Nr[i] = N[i]^-1 % M[i] 
    // Nr 是N在M[i]的逆元
    for(int i = 0;i < M.size();++i) {
        N[i] = Mm / M[i];
        Nr[i] = inv(N[i],M[i]);
        res[i] = N[i] * Nr[i] * R[i];
    }
    i128 ans = 0;
    for(int i = 0;i < M.size();++i) ans += res[i];
    return ans % Mm;
}


istream &operator >> (istream &os,i128 &x){
    string s;
    os >> s;
    if(s.front() == '-'){
        for(int i = 1;i < s.size();++i) x = x * 10 + (s[i] - '0');
        x = -x;
    }else{
        for(int i = 0;i < s.size();++i) x = x * 10 + (s[i] - '0');
    }
    return os;
}

ostream &operator << (ostream &os,i128 x){
    string s;
    if(x == 0){
        os << 0;
        return os;
    }
    if(x < 0){
        os << '-';
        x = -x;
    }
    while(x){
        s.push_back(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(),s.end());
    os << s;
    return os;
}

int main(){
    int N;
    cin >> N;
    vector<i128> m,r;
    m.resize(N),r.resize(N);
    for(int i = 0;i < N;++i) cin >> r[i];
    for(int i = 0;i < N;++i) cin >> m[i];
    cout << CRT(m,r) << endl;
    return 0;
}
```
