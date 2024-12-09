class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    vector<bool> answer;
    answer.reserve(queries.size());
    int n = nums.size();

    if (n == 1) {
      for (const auto &q : queries) {
        answer.push_back(true);
      }
      return answer;
    }

    vector<int> parityPairs(n - 1);
    for (int i = 0; i < n - 1; i++) {
      parityPairs[i] = ((nums[i] & 1) == (nums[i + 1] & 1));
    }

    vector<int> prefixSum(n);
    prefixSum[0] = parityPairs[0];
    for (int i = 1; i < n - 1; i++) {
      prefixSum[i] = prefixSum[i - 1] + parityPairs[i];
    }

    for (const auto &q : queries) {
      int left = q[0];
      int right = q[1];

      if (left == right) {
        answer.push_back(true);
        continue;
      }

      int violations = (left == 0) ? prefixSum[right - 1]
                                   : prefixSum[right - 1] -
                                         (left > 0 ? prefixSum[left - 1] : 0);
      answer.push_back(violations == 0);
    }

    return answer;
  }
};