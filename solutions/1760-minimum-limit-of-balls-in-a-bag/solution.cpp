class Solution {
public:
  bool canAchievePenalty(vector<int> &nums, int maxOps, int penalty) {
    long long operations = 0;
    for (int num : nums) {
      operations += (num - 1) / penalty;
    }
    return operations <= maxOps;
  }

  int minimumSize(vector<int> &nums, int maxOperations) {
    int left = 1;
    int right = *max_element(nums.begin(), nums.end());

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (canAchievePenalty(nums, maxOperations, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};