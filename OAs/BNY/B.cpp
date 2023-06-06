/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pp pair<int, int>

vector<int> solve(int N, vector<int> Arr) {
    for(int i = 0; i < N; i++)
        Arr[i]--;

    vector<int>ans(N, 0);
    vector<bool> vis(N,false);
    for(int i = 0; i < N; i++) {
        if(vis[i])continue;
        vector<int>aa;
        int culprit = -1, last = 0;;
        function<void(int)> dfs = [&](int u) {
            if(!vis[u]) {
                vis[u] = true;
                aa.push_back(u);
                dfs(Arr[u]);
            }
            else {
                culprit = u;
                last = ans[culprit];
                return;
            }

        };
        dfs(i);


        bool f = false;
        int nn = last + aa.size();

        for(auto &x : aa) {
            if(culprit == x)f = true;
            ans[x] = f ? nn : nn--;

        }

    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)cin >> x;
    vector<int> ans = solve(n, a);
    for(auto &x : ans)
        cout << x << " ";
    cout << endl;


    return 0;
}