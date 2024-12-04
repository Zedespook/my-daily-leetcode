class Solution {
public:
  vector<int> resultsArray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> results(n - k + 1);

    for (int i = 0; i <= n - k; i++) {
      bool isSorted = true;
      bool isConsecutive = true;

      for (int j = i; j < i + k - 1; j++) {
        if (nums[j] >= nums[j + 1]) {
          isSorted = false;
          break;
        }
        if (nums[j + 1] - nums[j] != 1) {
          isConsecutive = false;
          break;
        }
      }

      results[i] = (isSorted && isConsecutive) ? nums[i + k - 1] : -1;
    }

    return results;
  }
};