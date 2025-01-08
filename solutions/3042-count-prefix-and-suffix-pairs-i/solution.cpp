class Solution {
private:
  bool isPrefixAndSuffix(const string &str1, const string &str2) {
    if (str1.length() > str2.length()) {
      return false;
    }

    // Check prefix
    if (str2.substr(0, str1.length()) != str1) {
      return false;
    }

    // Check suffix
    if (str2.substr(str2.length() - str1.length()) != str1) {
      return false;
    }

    return true;
  }

public:
  int countPrefixSuffixPairs(vector<string> &words) {
    int count = 0;
    int n = words.size();

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (isPrefixAndSuffix(words[i], words[j])) {
          count++;
        }
      }
    }

    return count;
  }
};