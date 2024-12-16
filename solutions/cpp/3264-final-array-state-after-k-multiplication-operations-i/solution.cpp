class Solution {
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    vector<int> result = nums;

    for (int i = 0; i < k; i++) {
      int minIdx = 0;
      for (int j = 1; j < result.size(); j++) {
        if (result[j] < result[minIdx]) {
          minIdx = j;
        }
      }

      result[minIdx] *= multiplier;
    }

    return result;
  }
};