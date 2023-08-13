[P4391 [BOI2009] Radio Transmission 无线传输](https://www.luogu.com.cn/problem/P4391)

> 字符串哈希

```cpp
#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using string = std::string;
template<typename T>
using Vec = std::vector<T>;
template<typename T1, typename T2>
using Pr = std::pair<T1, T2>;
template<typename T>
using Set = std::set<T>;
template<typename T>
using USet = std::unordered_set<T>;
template<typename T1, typename T2>
using Mp = std::map<T1, T2>;
template<typename T1, typename T2>
using UMp = std::unordered_map<T1, T2>;


const ull BASE1 = 13331, BASE2 = 131;
const ull MOD1 = 1e9 + 9, MOD2 = 1e9 + 7;

const int N = 1e6 + 10;
char s[N];
ull H1[N], H2[N], P1[N], P2[N];


Pr<ull, ull> get_hash(int l, int r) {
    ull h1 = (H1[r] - H1[l - 1] * P1[r - l + 1] % MOD1 + MOD1) % MOD1;
    ull h2 = (H2[r] - H2[l - 1] * P2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return {h1, h2};
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    P1[0] = 1, P2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        P1[i] = (P1[i - 1] * BASE1) % MOD1;
        P2[i] = (P2[i - 1] * BASE2) % MOD2;
        H1[i] = (H1[i - 1] * BASE1 + s[i]) % MOD1;
        H2[i] = (H2[i - 1] * BASE2 + s[i]) % MOD2;
    }

    for (int len = 1; len <= n; ++len) {
        auto h1 = get_hash(1,n - len);
        auto h2 = get_hash(1 + len,n);
        if(h1 == h2){
            printf("%d",len);
            exit(0);
        }
    }


    return 0;
}

```
