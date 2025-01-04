class Solution {
public:
  int countPalindromicSubsequence(string s) {
    // Store first and last occurrence of each character
    vector<int> first(26, -1);
    vector<int> last(26, -1);

    // Find first and last occurrence of each character
    for (int i = 0; i < s.length(); i++) {
      if (first[s[i] - 'a'] == -1) {
        first[s[i] - 'a'] = i;
      }
      last[s[i] - 'a'] = i;
    }

    int result = 0;

    // For each character as potential first and last character of palindrome
    for (int i = 0; i < 26; i++) {
      // If character appears at least twice
      if (first[i] != -1 && last[i] != first[i]) {
        // Count unique characters between first and last occurrence
        unordered_set<char> between;
        for (int j = first[i] + 1; j < last[i]; j++) {
          between.insert(s[j]);
        }
        result += between.size();
      }
    }

    return result;
  }
};