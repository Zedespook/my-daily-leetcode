class Solution {
public:
  int minimumTime(vector<vector<int>> &grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1)
      return -1;

    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        pq;
    pq.push({0, 0, 0});

    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    while (!pq.empty()) {
      auto [t, x, y] = pq.top();
      pq.pop();

      if (t > dist[x][y])
        continue;

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
          continue;

        int nt = t + 1;
        if (nt < grid[nx][ny]) {
          nt = grid[nx][ny] + ((grid[nx][ny] - nt) % 2);
        }

        if (nt < dist[nx][ny]) {
          dist[nx][ny] = nt;
          pq.push({nt, nx, ny});
        }
      }
    }

    return dist[m - 1][n - 1] == INT_MAX ? -1 : dist[m - 1][n - 1];
  }
};