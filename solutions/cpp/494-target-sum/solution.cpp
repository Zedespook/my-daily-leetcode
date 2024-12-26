class Solution {
private:
  unordered_map<string, int> memo;

  int dp(vector<int> &nums, int target, int index) {
    if (index == nums.size()) {
      return target == 0 ? 1 : 0;
    }

    string key = to_string(index) + "," + to_string(target);
    if (memo.find(key) != memo.end()) {
      return memo[key];
    }

    // Try adding nums[index]
    int addResult = dp(nums, target - nums[index], index + 1);
    // Try subtracting nums[index]
    int subtractResult = dp(nums, target + nums[index], index + 1);

    memo[key] = addResult + subtractResult;
    return memo[key];
  }

public:
  int findTargetSumWays(vector<int> &nums, int target) {
    memo.clear();
    return dp(nums, target, 0);
  }
};