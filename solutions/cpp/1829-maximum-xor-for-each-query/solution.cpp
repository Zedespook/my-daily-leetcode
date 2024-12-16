class Solution {
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    const int n = nums.size();
    vector<int> answer(n);
    const int mask = (1 << maximumBit) - 1;

    int running_xor = 0;
    for (int num : nums) {
      running_xor ^= num;
    }

    for (int i = 0; i < n; i++) {
      answer[i] = running_xor ^ mask;
      running_xor ^= nums[n - 1 - i];
    }

    return answer;
  }
};