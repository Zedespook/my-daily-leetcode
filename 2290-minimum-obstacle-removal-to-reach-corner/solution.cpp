class Solution {
public:
  int minimumObstacles(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    deque<pair<int, int>> dq;

    dist[0][0] = 0;
    dq.push_front({0, 0});

    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!dq.empty()) {
      auto [x, y] = dq.front();
      dq.pop_front();

      if (x == m - 1 && y == n - 1)
        return dist[x][y];

      for (auto [dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
          int newDist = dist[x][y] + grid[nx][ny];
          if (newDist < dist[nx][ny]) {
            dist[nx][ny] = newDist;
            if (grid[nx][ny] == 1)
              dq.push_back({nx, ny});
            else
              dq.push_front({nx, ny});
          }
        }
      }
    }
    return dist[m - 1][n - 1];
  }
};