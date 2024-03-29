[P2044 [NOI2012] 随机数生成器](https://www.luogu.com.cn/problem/P2044)

> 矩阵快速幂

```math
\begin{pmatrix}  a&1 \\  0&1\end{pmatrix}\begin{pmatrix} x_n\\ c\end{pmatrix}=\begin{pmatrix} a x_n + c\\ c\end{pmatrix}=\begin{pmatrix} x_{n + 1}\\ c\end{pmatrix}
```

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128;

ostream &operator<<(ostream &os, i128 val) {
    string s;
    if (val < 0) {
        val = -val;
        while (val != 0) {
            s.push_back((val % 10) + '0');
            val /= 10;
        }
        s.push_back('-');
        reverse(s.begin(), s.end());
        os << s;
        return os;
    } else if (val > 0) {
        while (val != 0) {
            s.push_back((val % 10) + '0');
            val /= 10;
        }
        reverse(s.begin(), s.end());
        os << s;
        return os;
    } else {
        os << 0;
        return os;
    }
}

istream &operator>>(istream &is, i128 &val) {
    string s;
    is >> s;
    val = 0;
    if (s.front() == '-') {
        for (int i = 1; i < s.size(); ++i)
            val = 10 * val + s[i] - '0';
        val = -val;
    } else {
        for (int i = 0; i < s.size(); ++i)
            val = 10 * val + s[i] - '0';
    }
    return is;
}

template<typename T>
struct Matrix {
    T md;
    int h, w;
    vector<vector<T>> M;

    explicit Matrix(int h = 0, int w = 0, T md = 1e9 + 7) : h(h), w(w), md(md) { M.assign(h, vector<T>(w, 0)); }


    void show() {
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cout << M[i][j] << " \n"[j == w - 1];
    }


    T &at(int x, int y) {
        assert(0 <= x && x < h && 0 <= y && y < w);
        return this->M[x][y];
    }

    static Matrix identityMatrix(int n, T md = 1e9 + 7) {
        Matrix res(n, n, md);
        for (int i = 0; i < n; ++i)
            res.M[i][i] = 1;
        return res;
    }

    bool is_same_size(const Matrix &rhs) const {
        return h == rhs.h && w == rhs.w;
    }

    Matrix transpose() const {
        Matrix res(w, h);
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                res.M[j][i] = this->M[i][j];
        return res;
    }


    bool operator==(const Matrix &rhs) const {
        return md == rhs.md &&
               h == rhs.h &&
               w == rhs.w &&
               M == rhs.M;
    }

    bool operator!=(const Matrix &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Matrix &rhs) = delete;

    bool operator<=(const Matrix &rhs) = delete;

    bool operator>(const Matrix &rhs) = delete;

    bool operator>=(const Matrix &rhs) = delete;

    Matrix operator-() const {
        Matrix res = *this;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                res.M[i][j] = -res.M[i][j];
        return res;
    }

    Matrix &operator+=(const Matrix &rhs) {
        assert(this->is_same_size(rhs));

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                this->M[i][j] += rhs.M[i][j];

        return *this;
    }

    Matrix operator+(const Matrix &rhs) const {
        Matrix res = *this;
        res += rhs;
        return res;
    }

    Matrix &operator-=(const Matrix &rhs) {
        *this += (-rhs);
        return *this;
    }

    Matrix operator-(const Matrix &rhs) const {
        Matrix res = *this;
        res -= rhs;
        return res;
    }

    Matrix &operator*=(const T rhs) {
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                this->M[i][j] *= rhs;
        return *this;
    }

    Matrix operator*(const T rhs) const {
        Matrix res = *this;
        res *= rhs;
        return res;
    }


    Matrix operator*(const Matrix &rhs) const {
        assert(this->w == rhs.h);

        // matrix(m * n)  * matrix(n * p)
        int m = this->h, n = this->w, p = rhs.w;
        Matrix res(this->h, rhs.w, this->md);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < p; ++j)
                for (int k = 0; k < n; ++k) {
                    res.M[i][j] += this->M[i][k] * rhs.M[k][j];
                    res.M[i][j] %= md;
                }
        return res;
    }


    Matrix &operator%=(T mod) {
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                this->M[i][j] %= mod;
        return *this;
    }

    Matrix operator%(T mod) const {
        Matrix res = *this;
        res %= mod;
        return res;
    }


    Matrix qmi(T b) {
        Matrix a = *this;
        Matrix res = identityMatrix(this->w, this->md);
        while (b) {
            if (b & 1) {
                res = a * res % a.md;
            }
            a = a * a % a.md;
            b = b / 2;
        }
        return res;
    }

};


using Mr = Matrix<i128>;


int main() {
    i128 m, a, c, x0, n, g;

    cin >> m >> a >> c >> x0 >> n >> g;

    Mr A(2, 2, m), v0(2, 1, m);
    A.at(0, 0) = a;
    A.at(0, 1) = 1;
    A.at(1, 1) = 1;
    v0.at(0, 0) = x0;
    v0.at(1, 0) = c;

    Mr mul = A.qmi(n);
    Mr res = mul * v0;

    cout << res.at(0, 0) % g << endl;

    return 0;
}

```
