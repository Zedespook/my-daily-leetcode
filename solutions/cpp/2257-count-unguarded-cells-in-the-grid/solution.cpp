class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    vector<vector<int>> grid(m, vector<int>(n));

    for (const auto &w : walls) {
      grid[w[0]][w[1]] = 1;
    }

    for (const auto &g : guards) {
      grid[g[0]][g[1]] = 2;
    }

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    for (const auto &g : guards) {
      for (int dir = 0; dir < 4; ++dir) {
        int x = g[0] + dx[dir];
        int y = g[1] + dy[dir];

        while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 1 &&
               grid[x][y] != 2) {
          grid[x][y] = 3;
          x += dx[dir];
          y += dy[dir];
        }
      }
    }

    int unguarded = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          ++unguarded;
        }
      }
    }

    return unguarded;
  }
};