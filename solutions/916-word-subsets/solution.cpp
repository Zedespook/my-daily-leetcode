class Solution {
private:
  // Helper function to count character frequencies in a string
  vector<int> getCharCount(const string &word) {
    vector<int> count(26, 0);
    for (char c : word) {
      count[c - 'a']++;
    }
    return count;
  }

public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    // Get maximum frequency required for each character from words2
    vector<int> maxFreq(26, 0);
    for (const string &word : words2) {
      vector<int> currFreq = getCharCount(word);
      for (int i = 0; i < 26; i++) {
        maxFreq[i] = max(maxFreq[i], currFreq[i]);
      }
    }

    // Check each word in words1
    vector<string> result;
    for (const string &word : words1) {
      vector<int> freq = getCharCount(word);
      bool isUniversal = true;

      // Check if word has sufficient frequency for each required character
      for (int i = 0; i < 26; i++) {
        if (freq[i] < maxFreq[i]) {
          isUniversal = false;
          break;
        }
      }

      if (isUniversal) {
        result.push_back(word);
      }
    }

    return result;
  }
};