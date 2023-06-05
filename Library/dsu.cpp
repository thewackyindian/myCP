#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, siz, rank;
    int components = 0;
    DSU(int n = -1) {
        if (n >= 0)
            init(n);
    }
    void init(int n) {
        parent.resize(n + 1), siz.assign(n + 1, 1), rank.assign(n + 1, -1);
        components = n;
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        //by size
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y])
            swap(x, y);
        parent[y] = x;
        siz[x] += siz[y];
        components--;
        return true;
    }
    bool merge(int a, int b) {
      //by rank
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
};







//atcoder


// struct dsu {
//   public:
//     dsu() : _n(0) {}
//     explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

//     int merge(int a, int b) {
//         assert(0 <= a && a < _n);
//         assert(0 <= b && b < _n);
//         int x = leader(a), y = leader(b);
//         if (x == y) return x;
//         if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
//         parent_or_size[x] += parent_or_size[y];
//         parent_or_size[y] = x;
//         return x;
//     }

//     bool same(int a, int b) {
//         assert(0 <= a && a < _n);
//         assert(0 <= b && b < _n);
//         return leader(a) == leader(b);
//     }

//     int leader(int a) {
//         assert(0 <= a && a < _n);
//         if (parent_or_size[a] < 0) return a;
//         return parent_or_size[a] = leader(parent_or_size[a]);
//     }

//     int size(int a) {
//         assert(0 <= a && a < _n);
//         return -parent_or_size[leader(a)];
//     }

//     std::vector<std::vector<int>> groups() {
//         std::vector<int> leader_buf(_n), group_size(_n);
//         for (int i = 0; i < _n; i++) {
//             leader_buf[i] = leader(i);
//             group_size[leader_buf[i]]++;
//         }
//         std::vector<std::vector<int>> result(_n);
//         for (int i = 0; i < _n; i++) {
//             result[i].reserve(group_size[i]);
//         }
//         for (int i = 0; i < _n; i++) {
//             result[leader_buf[i]].push_back(i);
//         }
//         result.erase(
//             std::remove_if(result.begin(), result.end(),
//                            [&](const std::vector<int>& v) { return v.empty(); }),
//             result.end());
//         return result;
//     }

//   private:
//     int _n;
//     // root node: -1 * component size
//     // otherwise: parent
//     std::vector<int> parent_or_size;
// };

