class Solution {
public:
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    long long sum = 0;
    int neg_count = 0;
    int min_abs = INT_MAX;
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sum += abs(matrix[i][j]);
        min_abs = min(min_abs, abs(matrix[i][j]));
        if (matrix[i][j] < 0)
          neg_count++;
      }
    }

    return neg_count % 2 == 0 ? sum : sum - 2 * min_abs;
  }
};