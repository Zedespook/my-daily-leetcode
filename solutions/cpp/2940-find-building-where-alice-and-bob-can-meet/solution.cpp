#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int> &heights,
                                      vector<vector<int>> &queries) {
    int n = heights.size();
    int q = queries.size();

    // Add index to queries for later sorting
    for (int i = 0; i < q; ++i) {
      queries[i].push_back(i);
    }

    // Sort queries based on max(heights[a], heights[b]) in descending order
    sort(queries.begin(), queries.end(), [&](const auto &a, const auto &b) {
      return max(heights[min(a[0], a[1])], heights[max(a[0], a[1])]) >
             max(heights[min(b[0], b[1])], heights[max(b[0], b[1])]);
    });

    // Add index to heights for later sorting
    vector<pair<int, int>> indexedHeights(n);
    for (int i = 0; i < n; ++i) {
      indexedHeights[i] = {heights[i], i};
    }

    // Sort heights in descending order
    sort(indexedHeights.rbegin(), indexedHeights.rend());

    vector<int> ans(q);
    vector<int> bit(n + 1, n); // Initialize BIT with n (out of bounds index)

    auto update = [&](int i, int val) {
      while (i > 0) {
        bit[i] = min(bit[i], val);
        i -= i & -i;
      }
    };

    auto query = [&](int i) {
      int res = n;
      while (i <= n) {
        res = min(res, bit[i]);
        i += i & -i;
      }
      return res;
    };

    int j = 0;
    for (const auto &qry : queries) {
      int a = qry[0];
      int b = qry[1];
      int idx = qry[2];

      if (a == b) {
        ans[idx] = a;
        continue;
      }

      if (a > b) {
        swap(a, b);
      }

      if (heights[a] < heights[b]) {
        ans[idx] = b;
        continue;
      }

      int targetHeight = max(heights[a], heights[b]);

      // Update BIT with buildings taller than current targetHeight
      while (j < n && indexedHeights[j].first > targetHeight) {
        update(indexedHeights[j].second + 1, indexedHeights[j].second);
        j++;
      }

      // Query BIT for leftmost building reachable from b
      int res = query(b + 1);
      ans[idx] = (res == n) ? -1 : res;
    }

    return ans;
  }
};