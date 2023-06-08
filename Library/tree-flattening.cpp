/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <stack>
using namespace std;

#define int int64_t
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pp pair<int, int>

// Flattening means make an array of tree nodes
// ->any subtree would be present as a range in the array

// Tree can have multiple Flattened trees

// updates/queries on trees --> updates/queries over a range -->

void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>>g(n  + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>flattened;
    vector<int>start(n + 1, -1), end(n + 1, -1);
    vector<bool> vis(n + 1,false);
    function<void(int)> dfs = [&](int u) {
        flattened.push_back(u);
        start[u] = sz(flattened);
        vis[u] = true;

        for(auto &v : g[u]) {
            if(vis[v]) continue;
            dfs(v);
        }
        end[u] = sz(flattened);
    };
    dfs(1);

}

signed main() {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int cases = 1;
    cin >> cases;
    for (int tc = 1; tc <= cases; tc++) {
        solve();
    }

    return 0;
}