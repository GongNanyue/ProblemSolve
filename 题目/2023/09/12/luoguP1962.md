[P1962 斐波那契数列](https://www.luogu.com.cn/problem/P1962)

> 矩阵快速幂

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Matrix {
    static ll md;
    ll h, w;
    vector<vector<ll>> M;

    explicit Matrix(ll h = 0, ll w = 0) : h(h), w(w) { M.assign(h, vector<ll>(w, 0)); }

    void show() {
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cout << M[i][j] << " \n"[j == w - 1];
    }


    ll &at(ll x, ll y) {
        if (x < 0 || x >= h || y < 0 || y >= w) throw out_of_range("The index out of Matrix bound");
        return this->M[x][y];
    }

    void mode(ll md) {
        for (ll i = 0; i < h; ++i)
            for (ll j = 0; j < w; ++j)
                this->M[i][j] %= md;

    }

    static Matrix identityMatrix(ll n) {
        Matrix res(n, n);
        for (ll i = 0; i < n; ++i)
            res.M[i][i] = 1;
        return res;
    }

    bool is_same_size(const Matrix &rhs) const {
        return h == rhs.h && w == rhs.w;
    }

    Matrix transpose() const {
        Matrix res(w, h);
        for (ll i = 0; i < h; ++i)
            for (ll j = 0; j < w; ++j)
                res.M[j][i] = this->M[i][j];
        return res;
    }


    bool operator==(const Matrix &rhs) const {
        return h == rhs.h &&
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
        for (ll i = 0; i < h; ++i)
            for (ll j = 0; j < w; ++j)
                res.M[i][j] = -res.M[i][j];
        return res;
    }

    Matrix &operator+=(const Matrix &rhs) {
        assert(this->is_same_size(rhs));

        for (ll i = 0; i < h; ++i)
            for (ll j = 0; j < w; ++j)
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

    Matrix &operator*=(const ll rhs) {
        for (ll i = 0; i < h; ++i)
            for (ll j = 0; j < w; ++j)
                this->M[i][j] *= rhs;
        return *this;
    }

    Matrix operator*(const ll rhs) const {
        Matrix res = *this;
        res *= rhs;
        return res;
    }


    Matrix operator*(const Matrix &rhs) const {
        assert(this->w == rhs.h);

        // matrix(m * n)  * matrix(n * p)
        ll m = this->h, n = this->w, p = rhs.w;
        Matrix res(this->h, rhs.w);

        for (ll i = 0; i < m; ++i)
            for (ll j = 0; j < p; ++j)
                for (ll k = 0; k < n; ++k) {
                    res.M[i][j] += this->M[i][k] * rhs.M[k][j];
                    res.M[i][j] %= md;
                }
        return res;
    }


    Matrix &operator%=(ll mod) {
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                this->M[i][j] %= mod;
        return *this;
    }

    Matrix operator%(ll mod) const {
        Matrix res = *this;
        res %= mod;
        return res;
    }


    static Matrix qmi(Matrix a, ll b) {
        Matrix res = identityMatrix(a.w);

        while (b) {
            if (b & 1) {
                res = a * res % md;
            }
            a = a * a % md;
            b = b / 2;
        }

        return res;
    }

};

ll Matrix::md = 1e9 + 7;


int main() {

    Matrix v0(2, 1), A(2, 2);
    v0.at(0, 0) = v0.at(1, 0) = 1;
    A.at(0, 0) = A.at(0, 1) = A.at(1, 0) = 1;


    ll x;
    cin >> x;
    if (x <= 2) cout << 1 << "\n";
    else {
        Matrix mul = Matrix::qmi(A, x - 2);
        Matrix v = mul * v0;

        cout << v.at(0, 0) << "\n";
    }


    return 0;
}
```
