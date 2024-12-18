class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    vector<long long> freq(26, 0);
    for (char c : s) {
      freq[c - 'a']++;
    }

    string result;
    int lastChar = -1;
    int consecutiveCount = 0;

    while (true) {
      bool added = false;

      for (int i = 25; i >= 0; i--) {
        if (freq[i] == 0 ||
            (i == lastChar && consecutiveCount == repeatLimit)) {
          continue;
        }

        result += (char)(i + 'a');
        freq[i]--;

        if (i == lastChar) {
          consecutiveCount++;
        } else {
          lastChar = i;
          consecutiveCount = 1;
        }

        added = true;
        break;
      }

      if (!added)
        break;
    }

    return result;
  }
};