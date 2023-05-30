https://codeforces.com/problemset/problem/580/C

#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> adjlst;
vector<int> degree;
vector<bool> cat;
vector<int> cnt;
vector<int> conti;
void bfs() {
    vector<bool> vis(n + 1);
    queue<int> q;
    vis[1] = true;
    q.emplace(1);
    cnt[1] = cat[1];
    conti[1] = cat[1];
    while (!q.empty()) {
        int hd = q.front();
        q.pop();
        for (auto adj: adjlst[hd]) {
            if (!vis[adj]) {
                q.emplace(adj);
                vis[adj] = true;
                if(!cat[hd] && !cat[adj])
                    conti[adj] = 0;
                else if(!cat[hd] && cat[adj])
                    conti[adj] = 1;
                else if(cat[hd] && !cat[adj])
                    conti[adj] = 0;
                else
                    conti[adj] = conti[hd] + 1;

                cnt[adj] = max(cnt[hd],conti[adj]);

            }
        }
    }
}

int main() {
    cin >> n >> m;
    adjlst.resize(n + 1, vector<int>());
    cnt.resize(n + 1);
    cat.resize(n + 1);
    degree.resize(n+1);
    conti.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        cat[i] = (val == 1);
    }

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adjlst[a].emplace_back(b);
        adjlst[b].emplace_back(a);
        degree[a]++;
        degree[b]++;
    }
    bfs();
    int res = 0;

    for(int i = 2;i <= n;++i)
        if(degree[i] == 1  && cnt[i] <= m)
            res++;
    cout << res << "\n";
    return 0;
}
