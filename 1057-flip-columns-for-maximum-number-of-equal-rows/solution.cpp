class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    unordered_map<string, int> patterns;
    int result = 0;

    for (int i = 0; i < m; i++) {
      string pattern;
      pattern.reserve(n);

      int first = matrix[i][0];
      for (int j = 0; j < n; j++) {
        pattern += (matrix[i][j] == first ? '0' : '1');
      }

      result = max(result, ++patterns[pattern]);
    }

    return result;
  }
};