class Solution {
private:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  bool isVowelString(const string &s) {
    return !s.empty() && isVowel(s[0]) && isVowel(s.back());
  }

public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    int n = words.size();
    // Create prefix sum array
    vector<int> prefix(n + 1, 0);

    // Build prefix sum array
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + isVowelString(words[i]);
    }

    // Process queries
    vector<int> result;
    result.reserve(queries.size());

    for (const auto &query : queries) {
      int left = query[0];
      int right = query[1];
      result.push_back(prefix[right + 1] - prefix[left]);
    }

    return result;
  }
};