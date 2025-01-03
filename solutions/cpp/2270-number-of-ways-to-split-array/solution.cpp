class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    // Use long long to handle potential integer overflow
    long long totalSum = 0;
    long long leftSum = 0;
    int validSplits = 0;
    int n = nums.size();

    // Calculate total sum first
    for (int num : nums) {
      totalSum += num;
    }

    // Check each possible split point except the last element
    for (int i = 0; i < n - 1; i++) {
      leftSum += nums[i];
      long long rightSum = totalSum - leftSum;

      // If left sum is greater than or equal to right sum, it's a valid split
      if (leftSum >= rightSum) {
        validSplits++;
      }
    }

    return validSplits;
  }
};