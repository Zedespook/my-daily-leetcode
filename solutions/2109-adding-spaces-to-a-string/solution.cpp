class Solution {
public:
  string addSpaces(string s, vector<int> &spaces) {
    string result(s.length() + spaces.size(), ' ');
    int spaceIdx = spaces.size() - 1;
    int resultIdx = result.length() - 1;

    for (int i = s.length() - 1; i >= 0; i--) {
      result[resultIdx--] = s[i];
      if (spaceIdx >= 0 && i == spaces[spaceIdx]) {
        resultIdx--;
        spaceIdx--;
      }
    }

    return result;
  }
};