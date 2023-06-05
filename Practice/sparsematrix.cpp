#include <unordered_map>
#include <vector>

//HashTable solution takes more time to solve the test cases, and it will pay off in larger set.

class Solution {
public:
  std::vector<std::vector<int>> multiply(std::vector<std::vector<int>> &A,
                                         std::vector<std::vector<int>> &B) {
    int m = A.size();
    int n = A[0].size();
    int l = B[0].size();
    std::vector<std::vector<int>> C(m, std::vector<int>(l, 0));
    // i, j, value
    std::unordered_map<int, std::unordered_map<int, int>> map;

    for (int i = 0; i < n; i++) {
      map.emplace(i, std::unordered_map<int, int>());
      for (int j = 0; j < l; j++) {
        if (B[i][j] != 0) {
          map[i].emplace(j, B[i][j]);
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (A[i][j] != 0) {
          for (auto &p : map[j]) {
            C[i][p.first] += A[i][j] * p.second;
          }
        }
      }
    }

    return C;
  }
};
