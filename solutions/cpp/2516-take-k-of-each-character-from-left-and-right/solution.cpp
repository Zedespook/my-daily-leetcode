class Solution {
public:
  int takeCharacters(string s, int k) {
    int n = s.length();
    if (k == 0)
      return 0;

    vector<int> total(3);
    for (char c : s)
      total[c - 'a']++;

    for (int i = 0; i < 3; i++) {
      if (total[i] < k)
        return -1;
    }

    vector<int> freq(3);
    int left = 0;
    int maxWindow = 0;

    for (int right = 0; right < n; right++) {
      freq[s[right] - 'a']++;

      while (left <= right &&
             (freq[0] > total[0] - k || freq[1] > total[1] - k ||
              freq[2] > total[2] - k)) {
        freq[s[left] - 'a']--;
        left++;
      }

      maxWindow = max(maxWindow, right - left + 1);
    }

    return n - maxWindow;
  }
};