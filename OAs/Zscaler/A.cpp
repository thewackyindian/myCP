/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    stack<int>st;
    for(auto &x : a) {
        cin >> x;
        if(st.empty()) st.push(x);
        else{
            if(st.top() != 0 && (st.top() % x  || x % st.top())){
                int y = st.top() % x ? st.top() % x : x % st.top();
                st.pop();
                st.push(y);
            }
            else{
                st.push(x);
            }
        }
    }
    cout << (st.size() + 1) / 2 << endl;
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