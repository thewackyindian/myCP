#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>>g(n  + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }


    vector<bool> vis(n + 1,false), dfs_finished(n + 1, false);
    stack<int> st;
    vector<int> cycle;
    function<void(int)> dfs = [&](int u) {
        st.push(u);
        vis[u] = true;

        for(auto &v : g[u]) {
            if(vis[v]) {
                if(!dfs_finished[v]) {
                    //cycle
                    while(st.top() != v) {
                        cycle.push_back(st.top());
                        st.pop();
                    }
                    exit(0);
                }
            }
            dfs(v);
        }
        st.pop();
        dfs_finished[u] = true;
    };
    dfs(1);

}





