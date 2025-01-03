class Solution {
public:
  vector<vector<int>> adj;
  vector<int> vals;
  int k;
  int result = 0;

  long long dfs(int node, int parent) {
    long long sum = vals[node];

    for (int child : adj[node]) {
      if (child != parent) {
        sum += dfs(child, node);
      }
    }

    if (sum % k == 0) {
      result++;
      return 0;
    }
    return sum;
  }

  int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                              vector<int> &values, int k) {
    adj.resize(n);
    vals = values;
    this->k = k;

    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    dfs(0, -1);
    return result;
  }
};