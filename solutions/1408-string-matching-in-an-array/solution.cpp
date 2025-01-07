class Solution {
public:
  vector<string> stringMatching(vector<string> &words) {
    vector<string> result;

    // Check each word against all other words
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        // Skip comparing word with itself
        if (i != j && words[j].find(words[i]) != string::npos) {
          result.push_back(words[i]);
          // Break inner loop once we find a match
          break;
        }
      }
    }

    return result;
  }
};