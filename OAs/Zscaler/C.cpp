/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) {
        cin >> x;
    }
    map<int,vector<int>> pos;
    for(int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }
    int ans  = 0;
    int cur = -1;
    for(auto &x : pos) {
        if(x.second.size() == 1) continue;
        auto it = upper_bound(x.second.begin(), x.second.end(), cur);
        int dif = it - x.second.begin();
        if(dif >= 2) {
            cout << -1 << endl;
            return;
        }
        else{
            if(dif == 1) {
                cur = x.second[x.second.size() - 2];
            }
            else{
                cur = x.second.back();
            }
            ans += x.second.size() - 1;
        }
    }
    cout << ans << endl;
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