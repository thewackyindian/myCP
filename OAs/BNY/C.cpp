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

class dsu {
  public:
  vector<int> p;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

long long solve(int N, int M, vector<int> A, vector<vector<int>>E) {
    vector<int>deg(N, N - 1);

    set<pair<int,int>>removed;
    for(auto &x : E) {
        x[0]--;x[1]--;
        removed.insert({x[0], x[1]});
        deg[x[0]]--;
        deg[x[1]]--;
    }
    dsu d(N);
    int tot = (N * (N - 1)) / 2;
    if(count(deg.begin(), deg.end(), 0) >= 1 || (tot - M < N - 1)){
        return -1;
    }
    vector<int>order(N);
    iota(order.begin(), order.end(), 0);

    int taken = 0;
    long long cost = 0;

    sort(order.begin(), order.end(), [&](int i, int j){
        if(A[i] < A[j]) return true;
        else if(A[i] == A[j]){
            return deg[i] > deg[j];
        }
        return false;
    });

    for(int i = 0 ;i < N ; i++) {
        int u = order[i];

        vector<int>edges;

        for(int v = 0; v < N; v++) {
            if(v != u && (removed.find({u, v}) == removed.end() && removed.find({v, u}) == removed.end())) {
                edges.push_back(v);
            }
        }

        sort(edges.begin(), edges.end(), [&](int ii, int jj){
            return A[ii] < A[jj];
        });
        for(auto &x : edges){
            if(d.get(x) == d.get(u))
                continue;

            cost += A[u] * A[x];
            taken++;
            if(taken == N - 1)
                break;
            removed.insert({u, x});
            d.unite(u,x);
        }

        if(taken == N - 1)
                break;
    }


    return (taken < N - 1) ? -1 : cost;

}

signed main() {
    int n , m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a)cin >> x;
    vector<vector<int>>g;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.push_back({u, v});

    }

    cout <<  solve(n, m, a, g) << endl;


    return 0;
}