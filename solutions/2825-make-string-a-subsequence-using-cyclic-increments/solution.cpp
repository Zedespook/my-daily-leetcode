class Solution {
public:
  bool canMakeSubsequence(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    int j = 0;

    for (int i = 0; i < n && j < m; i++) {
      char next = str1[i] == 'z' ? 'a' : str1[i] + 1;
      if (str1[i] == str2[j] || next == str2[j]) {
        j++;
      }
    }

    return j == m;
  }
};