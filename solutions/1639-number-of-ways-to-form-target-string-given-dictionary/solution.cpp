#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numWays(vector<string> &words, string target) {
    const int MOD = 1e9 + 7;
    int m = words[0].length(); // Length of each word
    int n = target.length();   // Length of target string

    // Count frequency of each character at each position in words
    vector<vector<long long>> freq(m, vector<long long>(26, 0));
    for (const string &word : words) {
      for (int i = 0; i < m; i++) {
        freq[i][word[i] - 'a']++;
      }
    }

    // dp[i][j] represents number of ways to form target[0...i-1] using first j
    // positions
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    // Initialize base case - empty string can be formed in one way
    for (int j = 0; j <= m; j++) {
      dp[0][j] = 1;
    }

    // For each position in target
    for (int i = 0; i < n; i++) {
      // For each position in words
      for (int j = 0; j < m; j++) {
        // Add ways to form current position using current character
        dp[i + 1][j + 1] = dp[i + 1][j];
        dp[i + 1][j + 1] =
            (dp[i + 1][j + 1] + (dp[i][j] * freq[j][target[i] - 'a']) % MOD) %
            MOD;
      }
    }

    return dp[n][m];
  }
};