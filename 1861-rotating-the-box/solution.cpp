class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid) {
    int m = boxGrid.size();
    int n = boxGrid[0].size();
    vector<vector<char>> rotated(n, vector<char>(m));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        rotated[j][m - 1 - i] = boxGrid[i][j];
      }
    }

    for (int j = 0; j < m; j++) {
      int bottom = n - 1;
      for (int i = n - 1; i >= 0; i--) {
        if (rotated[i][j] == '*') {
          bottom = i - 1;
        } else if (rotated[i][j] == '#') {
          if (i != bottom) {
            rotated[bottom][j] = '#';
            rotated[i][j] = '.';
          }
          bottom--;
        }
      }
    }

    return rotated;
  }
};