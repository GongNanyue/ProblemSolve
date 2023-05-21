//https://ac.nowcoder.com/acm/contest/28263/B
#include <iostream>
#include <iomanip>

using namespace std;


const int N = 1010;
double ept[N][N];
int n_, s_;

double cal(int i_, int j_) {
    if(i_ == n_ && j_ == s_ || i_ > n_ || j_ > s_)return 0;
    if (ept[i_][j_] != 0)return ept[i_][j_];
    double n = n_, s = s_, i = i_, j = j_;
    return ept[i_][j_] = (
            i * j +
            (n - i) * j * (cal(i_ + 1, j_) + 1) +
            i * (s - j) * (cal(i_, j_ + 1) + 1) +
            (n - i) * (s - j) * (cal(i_ + 1, j_ + 1) + 1)
                          )/ (n * s - i * j);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n_ >> s_;

    cout << setprecision(4) << fixed << cal(0,0) << "\n";
    return 0;
}
