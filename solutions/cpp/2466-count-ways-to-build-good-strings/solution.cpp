class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    const int MOD = 1e9 + 7;
    // dp[i] represents the number of good strings of length i
    vector<int> dp(high + 1, 0);

    // Empty string has 1 way
    dp[0] = 1;

    // For each length i, calculate number of good strings
    for (int i = 1; i <= high; i++) {
      // Add strings that can be formed by appending 'zero' zeros
      if (i >= zero) {
        dp[i] = (dp[i] + dp[i - zero]) % MOD;
      }
      // Add strings that can be formed by appending 'one' ones
      if (i >= one) {
        dp[i] = (dp[i] + dp[i - one]) % MOD;
      }
    }

    // Sum up all good strings with lengths from low to high
    int result = 0;
    for (int i = low; i <= high; i++) {
      result = (result + dp[i]) % MOD;
    }

    return result;
  }
};