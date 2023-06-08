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

template <typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>istream& operator >> (istream &is, T_container &v) {for(T &x : v) is >> x; return is;}
template <typename A, typename B>ostream &operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.first << ", " << p.second << ')';}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>ostream &operator<<(ostream &os, const T_container &v){    os << '{';string sep;for (const T &x : v)os << sep << x, sep = ", ";return os << '}';}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){static priority_queue<P, Q, R> U;U = M;out << "{ ";while(!U.empty())out << U.top() << " ", U.pop();return (out << "}");}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){static queue<P> U;U = M;out << "{ ";while(!U.empty())out << U.front() << " ", U.pop();return (out << "}");}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T){cerr << ' ' << H; dbg_out(T...);}
#ifdef LOCAL
    #define dbg(...) cerr << __func__ << " : " << __LINE__ << " " << "(" << #__VA_ARGS__ << ") : ",dbg_out(__VA_ARGS__);
#else
    #define dbg(...) 2529;
#endif
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int mod = 1e9 + 7, inf = 1e18L + 5, N = 2e5 + 5;
const string yes = "YES", no = "NO";

void solve() {
    int n , m;
    cin >> n >> m;
    //n -> days, m -> cities
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int x;
    cin >> x;

    vector<int> pref(m, 0), suf(m, 0), p(m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0) {
                p[j] = g[i][j];
            }
            else {
                int init = 0;
                if(j == 0) {
                    init = suf[j + 1];
                }
                else if(j == m - 1) {
                    init = pref[j - 1];
                }
                else{
                    init = max(pref[j - 1], suf[j + 1]);
                }
                p[j] = max(init - x, p[j]) + g[i][j];
            }
        }


        pref[0] = p[0];
        for (int j = 1; j < m; j++) {
            pref[j] = max(p[j], pref[j - 1]);
        }

        suf[m - 1] = p[m - 1];
        for (int j = m - 2; j >= 0; j--) {
            suf[j] = max(p[j], suf[j + 1]);
        }
    }
    cout << pref[m - 1] << endl;

    //SC: O(M)
    //TC: O(N * M)

}

signed main() {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    int cases = 1;
    // cin >> cases;
    for (int tc = 1; tc <= cases; tc++) {
        solve();
    }

    return 0;
}