class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    return countPairsLessEqual(nums, upper) -
           countPairsLessEqual(nums, lower - 1);
  }

private:
  long long countPairsLessEqual(vector<int> &nums, int target) {
    long long count = 0;
    int left = 0, right = nums.size() - 1;

    while (left < right) {
      if ((long long)nums[left] + nums[right] <= target) {
        count += right - left;
        left++;
      } else {
        right--;
      }
    }

    return count;
  }
};