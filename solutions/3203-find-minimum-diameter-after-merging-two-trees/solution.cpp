#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  int dfs(int u, int parent, const vector<vector<int>> &adj, int &maxDiameter) {
    int maxDepth1 = 0, maxDepth2 = 0;
    for (int v : adj[u]) {
      if (v != parent) {
        int depth = dfs(v, u, adj, maxDiameter) + 1;
        if (depth > maxDepth1) {
          maxDepth2 = maxDepth1;
          maxDepth1 = depth;
        } else if (depth > maxDepth2) {
          maxDepth2 = depth;
        }
      }
    }
    maxDiameter = max(maxDiameter, maxDepth1 + maxDepth2);
    return maxDepth1;
  }

  int treeDiameter(const vector<vector<int>> &edges, int n) {
    if (n == 1)
      return 0;
    vector<vector<int>> adj(n);
    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
    int maxDiameter = 0;
    dfs(0, -1, adj, maxDiameter);
    return maxDiameter;
  }

public:
  int minimumDiameterAfterMerge(vector<vector<int>> &edges1,
                                vector<vector<int>> &edges2) {
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    int diameter1 = treeDiameter(edges1, n);
    int diameter2 = treeDiameter(edges2, m);

    return max(
        {diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
  }
};
