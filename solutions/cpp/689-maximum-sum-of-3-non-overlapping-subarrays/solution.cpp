class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> sums(n - k + 1); // Store sums of all possible k-sized windows

    // Calculate sum of first window
    int sum = 0;
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    sums[0] = sum;

    // Calculate sums for remaining windows
    for (int i = k; i < n; i++) {
      sum = sum + nums[i] - nums[i - k];
      sums[i - k + 1] = sum;
    }

    // left[i] stores the index of max sum subarray from left to i
    vector<int> left(sums.size(), 0);
    int best = 0;
    for (int i = 0; i < sums.size(); i++) {
      if (sums[i] > sums[best]) {
        best = i;
      }
      left[i] = best;
    }

    // right[i] stores the index of max sum subarray from i to end
    vector<int> right(sums.size(), 0);
    best = sums.size() - 1;
    for (int i = sums.size() - 1; i >= 0; i--) {
      if (sums[i] >= sums[best]) { // >= for lexicographically smallest
        best = i;
      }
      right[i] = best;
    }

    // Find the best combination of three subarrays
    vector<int> result = {0, k,
                          k * 2}; // Initialize with first possible position
    int maxSum = 0;

    // Try all possible middle positions
    for (int i = k; i <= n - 2 * k; i++) {
      int l = left[i - k];  // Best position for left subarray
      int r = right[i + k]; // Best position for right subarray
      int total = sums[l] + sums[i] + sums[r];

      if (total > maxSum) {
        maxSum = total;
        result = {l, i, r};
      }
    }

    return result;
  }
};