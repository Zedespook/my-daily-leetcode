class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    // Create DP array to store minimum cost up to each day
    vector<int> dp(days.back() + 1, 0);
    unordered_set<int> travel_days(days.begin(), days.end());

    // Iterate through all days from 1 to last travel day
    for (int i = 1; i <= days.back(); i++) {
      // If not a travel day, cost remains same as previous day
      if (!travel_days.count(i)) {
        dp[i] = dp[i - 1];
        continue;
      }

      // Try all three pass options and take minimum
      dp[i] = dp[i - 1] + costs[0];                      // 1-day pass
      dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);  // 7-day pass
      dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]); // 30-day pass
    }

    return dp[days.back()];
  }
};