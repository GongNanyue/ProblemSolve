Codeforces Round 105 (Div. 2)
//https://codeforces.com/problemset/problem/148/D

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int ww, bb;
double p[N][N];

void getP() {
    for (int i = 1; i <= ww; ++i)
        p[i][0] = 1.0;
    for (int i = 0; i <= bb; ++i)
        p[0][i] = 0.0;

    for (int ii = 1; ii <= ww; ++ii)
        for (int jj = 1; jj <= bb; ++jj) {
            double i = ii, j = jj;
            p[ii][jj] = i / (i + j);
            if (ii >= 1 && jj >= 2)
                p[ii][jj] += p[ii - 1][jj - 2] * j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2);
            if (jj >= 3)
                p[ii][jj] += p[ii][jj - 3] * j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> ww >> bb;

    getP();
    cout << setprecision(10) << fixed
         << p[ww][bb] << "\n";


    return 0;
}
