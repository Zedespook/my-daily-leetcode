class Solution {
public:
  vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
    unordered_map<int, stack<int>> adj;
    unordered_map<int, int> in, out;

    for (auto &p : pairs) {
      adj[p[0]].push(p[1]);
      out[p[0]]++;
      in[p[1]]++;
    }

    int start = pairs[0][0];
    for (auto &[v, cnt] : out) {
      if (out[v] - in[v] == 1) {
        start = v;
        break;
      }
    }

    vector<vector<int>> res;
    dfs(start, adj, res);
    reverse(res.begin(), res.end());
    return res;
  }

  void dfs(int u, unordered_map<int, stack<int>> &adj,
           vector<vector<int>> &res) {
    while (!adj[u].empty()) {
      int v = adj[u].top();
      adj[u].pop();
      dfs(v, adj, res);
      res.push_back({u, v});
    }
  }
};