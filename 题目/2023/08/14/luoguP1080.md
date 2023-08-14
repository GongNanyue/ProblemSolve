[P1080 [NOIP2012 提高组] 国王游戏](https://www.luogu.com.cn/problem/P1080)

> 贪心




```java
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        minister king = new minister();
        king.a = scanner.nextBigInteger();
        king.b = scanner.nextBigInteger();

        List<minister> m = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            BigInteger a, b;
            a = scanner.nextBigInteger();
            b = scanner.nextBigInteger();
            m.add(new minister(a, b));
        }
        Collections.sort(m);

        BigInteger k = king.a;
        BigInteger mx = BigInteger.valueOf(0);

        for (int i = 0; i < n; ++i) {
            mx = mx.max(k.divide(m.get(i).b));
            k = k.multiply(m.get(i).a);
        }

        System.out.println(mx);

    }

}


class minister implements Comparable {
    BigInteger a, b;

    public minister() {
    }

    public minister(BigInteger a, BigInteger b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public int compareTo(Object o) {
        minister rhs = (minister) o;
        BigInteger x = rhs.a, y = rhs.b;
        BigInteger p = a.multiply(b), q = x.multiply(y);
        return p.compareTo(q);
    }
}

```

```python
class minister:
    a = 0
    b = 0

    def __init__(self, x, y):
        self.a = x
        self.b = y

    def __lt__(self, other):
        return self.a * self.b < other.a * other.b


n = int(input())
a, b = map(int, input().split())
king = minister(a, b)
m = []
for i in range(n):
    a, b = map(int, input().split())
    m.append(minister(a, b))

m.sort()
k = king.a
mx = 0
for i in range(n):
    mx = max(mx, k // m[i].b)
    k = k * m[i].a

print(mx)

```
