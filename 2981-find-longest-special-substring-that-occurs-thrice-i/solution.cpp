class Solution {
public:
  int maximumLength(string s) {
    int n = s.length();
    int result = -1;

    for (int len = 1; len <= n; len++) {
      unordered_map<string, int> count;
      for (int i = 0; i <= n - len; i++) {
        string sub = s.substr(i, len);
        bool isSpecial = true;
        for (int j = 1; j < len; j++) {
          if (sub[j] != sub[0]) {
            isSpecial = false;
            break;
          }
        }
        if (isSpecial) {
          count[sub]++;
          if (count[sub] >= 3) {
            result = max(result, len);
          }
        }
      }
    }

    return result;
  }
};