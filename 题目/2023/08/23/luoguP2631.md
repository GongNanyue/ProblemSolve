[P2613 【模板】有理数取余](https://www.luogu.com.cn/problem/P2613)

> 乘法逆元

扩展欧几里得求逆元
```python
import math

md = 19260817

def exgcd(a, b):
    if a % b == 0:
        return 0, 1, b
    else:
        (x1, y1, d) = exgcd(b, a % b)
        x = y1
        y = x1 - a // b * y1
        return x, y, d


a = int(input())
b = int(input())
if math.gcd(b, md) == 1:
    (x, y, d) = exgcd(b, md)
    print(a * x % md)
else:
    print("Angry!")
```

快速幂+费马小定理求逆元
```python
import math

md = 19260817


def qmi(a, b):
    res = 1
    while b != 0:
        if b % 2 == 1:
            res = (res * a) % md
        a = (a * a) % md
        b = b // 2
    return res


a = int(input())
b = int(input())
if math.gcd(b, md) == 1:
    invb = qmi(b, md - 2)
    print(a * invb % md)
else:
    print("Angry!\n")
```
