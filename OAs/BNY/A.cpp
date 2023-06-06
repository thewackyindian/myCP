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


int solve(int N, vector<int> A) {

  if (A[0] != 0)
    return -1;

  int ans = 0;
  for (int i = 1; i < A.size(); i++) {
    if (A[i] - A[i - 1] == 0 && A[i] != 0) {
        ans += A[i];
    }
    else if (A[i] - A[i - 1] == 1) {
        ans++;
    }
    else if (A[i] - A[i - 1] > 2) {
        return -1;
    }
  }
  return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)cin >> x;
    cout <<  solve(n, a) << endl;
    return 0;
}