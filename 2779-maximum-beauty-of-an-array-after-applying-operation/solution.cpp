class Solution {
public:
  int maximumBeauty(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int maxBeauty = 1;

    int left = 0;

    for (int right = 1; right < n; right++) {
      while (left < right && nums[right] - nums[left] > 2 * k) {
        left++;
      }

      maxBeauty = max(maxBeauty, right - left + 1);
    }

    return maxBeauty;
  }
};