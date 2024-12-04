class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>> &queries) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
      adj[i].push_back(i + 1);
    }

    vector<int> answer;
    for (const auto &query : queries) {
      int u = query[0], v = query[1];
      adj[u].push_back(v);
      answer.push_back(bfs(adj, n));
    }
    return answer;
  }

private:
  int bfs(const vector<vector<int>> &adj, int n) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (int next : adj[curr]) {
        if (dist[next] == -1) {
          dist[next] = dist[curr] + 1;
          q.push(next);
        }
      }
    }
    return dist[n - 1];
  }
};