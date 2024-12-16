class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    if (k > n)
      return 0;

    unordered_map<int, int> freq;
    long long sum = 0, maxSum = 0;

    for (int i = 0; i < k; i++) {
      freq[nums[i]]++;
      sum += nums[i];
    }

    if (freq.size() == k)
      maxSum = sum;

    for (int i = k; i < n; i++) {
      freq[nums[i]]++;
      freq[nums[i - k]]--;

      if (freq[nums[i - k]] == 0) {
        freq.erase(nums[i - k]);
      }

      sum += nums[i] - nums[i - k];

      if (freq.size() == k) {
        maxSum = max(maxSum, sum);
      }
    }

    return maxSum;
  }
};