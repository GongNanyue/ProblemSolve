
[P3373 【模板】线段树 2](https://www.luogu.com.cn/problem/P3373)

> [线段树](https://github.com/GongNanyue/ProblemSolve/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%BA%BF%E6%AE%B5%E6%A0%91.md)

```cpp
#include <bits/stdc++.h>

using ll = long long;
ll Mod = 571373;
const ll N = 1e5+10;
ll n,q;
ll a[N],s[N<<2],t1[N<<2],t2[N<<2];
// t1 add lazy tag
// t2 mul lazy tag

void debug(){
    std::cerr << "s\n";
    for(int i = 1;i <= 4 * n;++i)
        std::cerr << s[i] << " \n"[i == 4 * n];

    std::cerr << "t1\n";
    for(int i = 1;i <= 4 * n;++i)
        std::cerr << t1[i] << " \n"[i == 4 * n];

    std::cerr << "t2\n";
    for(int i = 1;i <= 4 * n;++i)
        std::cerr << t2[i] << " \n"[i == 4 * n];

    std::cerr << "------------\n";
}

auto ls = [](ll p){return 2*p;};
auto rs = [](ll p){return 2*p+1;};

void add_p(ll p,ll l,ll r,ll k){
    s[p] = (s[p] + (r - l + 1) * k) % Mod;
    t1[p] = (t1[p] + k) % Mod;
}

void mul_p(ll p,ll k){
    s[p] = (s[p] * k) % Mod;
    t1[p] = (t1[p] * k) % Mod;
    t2[p] = (t2[p] * k) % Mod;
}


void push_up(ll p){
    s[p] = s[ls(p)] + s[rs(p)];
}

void push_down(ll p,ll l,ll r){
    if(t1[p] == 0 && t2[p] == 1) return;
    mul_p(ls(p),t2[p]),mul_p(rs(p),t2[p]);
    ll mid = (l + r)/2;
    add_p(ls(p),l,mid,t1[p]),add_p(rs(p),mid+1,r,t1[p]);
    t1[p] = 0,t2[p] = 1;
}


void build(ll p,ll l,ll r){
    t1[p] = 0,t2[p] = 1;

    if(l == r){
        s[p] = a[l];
    }else{
        ll mid = (l + r)/2;
        build(ls(p),l,mid),build(rs(p),mid+1,r);;
        push_up(p);
    }
}

ll ask_interval(ll p,ll l,ll r,ll L,ll R){
    if(R < l || r < L) return 0;
    if(L <= l && r <= R) return s[p];
    push_down(p,l,r);
    ll mid = (l + r)/2;
    return (ask_interval(ls(p),l,mid,L,R) + ask_interval(rs(p),mid+1,r,L,R)) % Mod;
}

void add_interval(ll p,ll l,ll r,ll L,ll R,ll k){
    if(R < l || r < L) return;
    if(L <= l && r <= R) return add_p(p,l,r,k);

    push_down(p,l,r);
    ll mid = (l + r) / 2;
    add_interval(ls(p),l,mid,L,R,k),add_interval(rs(p),mid+1,r,L,R,k);
    push_up(p);
}

void mul_interval(ll p,ll l,ll r,ll L,ll R,ll k){
    if(R < l || r < L) return;
    if(L <= l && r <= R) return mul_p(p,k);
    push_down(p,l,r);
    ll mid = (l + r)/2;
    mul_interval(ls(p),l,mid,L,R,k),mul_interval(rs(p),mid+1,r,L,R,k);
    push_up(p);
}


int main(){

//    setbuf(stdout, nullptr);
    std::cin >> n >> q >> Mod;
    for(int i = 1;i <= n;++i) std::cin >> a[i];

    build(1,1,n);

    ll op,x,y,k;
    while (q--){

        std::cin >> op;
        if(op == 1){
            std::cin >> x >> y >> k;
            mul_interval(1,1,n,x,y,k);
        }else if(op == 2){
            std::cin >> x >> y >> k;
            add_interval(1,1,n,x,y,k);
        }else if(op == 3){
            std::cin >> x >> y;
            std::cout << ask_interval(1,1,n,x,y) << "\n";
        }
    }
    return 0;
}
```
