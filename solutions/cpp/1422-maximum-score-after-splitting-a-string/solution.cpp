class Solution {
public:
  int maxScore(string s) {
    int maxScore = 0;
    int zeros = 0;
    int ones = count(s.begin(), s.end(), '1');

    // Try all splits except the last position
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == '0') {
        zeros++;
      } else {
        ones--;
      }
      maxScore = max(maxScore, zeros + ones);
    }

    return maxScore;
  }
};